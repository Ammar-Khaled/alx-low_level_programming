#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <elf.h>

/**
 * print_addr - prints the entry address
 * @buf: magic.
 * Return: no return.
 */
void print_addr(char *buf)
{
	int i;
	int begin;
	char sys;

	printf("  Entry point address:               0x");
	sys = buf[4] + '0';
	if (sys == '1') /* if 32-bit */
	{
		begin = 26;
		printf("80"); /*to indicate the start of 32-bit address field*/
		for (i = begin; i >= 22; i--)
		{
			if (buf[i] > 0)
				printf("%x", buf[i]);
			else if (buf[i] < 0)
				printf("%x", 256 + buf[i]);
		}
		/*if OS/ABI is Ubuntu Solaris*/
		if (buf[7] == 6)
			/*
			 * to indicate that the address
			 * is aligned on a 4-byte boundary
			 * append it with 00 at the end
			 */
			printf("00");
	}
	if (sys == '2')
	{
		begin = 26;
		for (i = begin; i > 23; i--)
		{
			if (buf[i] >= 0)
				printf("%02x", buf[i]);

			else if (buf[i] < 0)
				printf("%02x", 256 + buf[i]);
		}
	}
	printf("\n");
}

/**
 * print_type - prints type
 * @buf: magic.
 * Return: no return.
 */
void print_type(char *buf)
{
	char type = buf[16];

	if (buf[5] == 1)
		type = buf[16];
	else
		type = buf[17];

	printf("  Type:                              ");
	if (type == 0)
		printf("NONE (No file type)\n");
	else if (type == 1)
		printf("REL (Relocatable file)\n");
	else if (type == 2)
		printf("EXEC (Executable file)\n");
	else if (type == 3)
		printf("DYN (Shared object file)\n");
	else if (type == 4)
		printf("CORE (Core file)\n");
	else
		printf("<unknown: %x>\n", type);
}

/**
 * print_osabi - prints osabi
 * @buf: magic.
 * Return: no return.
 */
void print_osabi(char *buf)
{
	char osabi = buf[7];

	printf("  OS/ABI:                            ");
	if (osabi == 0)
		printf("UNIX - System V\n");
	else if (osabi == 2)
		printf("UNIX - NetBSD\n");
	else if (osabi == 6)
		printf("UNIX - Solaris\n");
	else
		printf("<unknown: %x>\n", osabi);

	printf("  ABI Version:                       %d\n", buf[8]);
}

/**
 * print_version - prints version
 * @buf: magic.
 * Return: no return.
 */
void print_version(char *buf)
{
	int version = buf[6];

	printf("  Version:                           %d", version);

	if (version == EV_CURRENT)
		printf(" (current)");

	printf("\n");
}
/**
 * print_data - prints data
 * @buf: magic.
 * Return: no return.
 */
void print_data(char *buf)
{
	char data = buf[5];

	printf("  Data:                              2's complement");
	if (data == 1)
		printf(", little endian\n");

	if (data == 2)
		printf(", big endian\n");
}
/**
 * print_magic - prints magic info.
 * @buf: magic.
 * Return: no return.
 */
void print_magic(char *buf)
{
	int i;

	printf("ELF Header:\n");
	printf("  Magic:  ");

	for (i = 0; i < 16; i++)
		printf(" %02x", buf[i]);

	printf("\n");
}

/**
 * print_class - check the system architecture.
 * @buf: magic.
 * Return: no return.
 */
void print_class(char *buf)
{
	char sys = buf[4] + '0';

	if (sys == '1')
		printf("  Class:                             ELF32\n");

	if (sys == '2')
		printf("  Class:                             ELF64\n");
}

/**
 * check_elf - check if it is an elf file.
 * @buf: magic.
 * Return: 1 if it is an elf file. 0 if not.
 */
int check_elf(char *buf)
{
	int addr = (int)buf[0];
	char E = buf[1];
	char L = buf[2];
	char F = buf[3];

	/*elf should start with 7f 45 4c 46*/
	if (addr == 127 && E == 'E' && L == 'L' && F == 'F')
		return (1);

	return (0);
}

/**
 * main - display elf header
 * @argc: number of arguments.
 * @argv: arguments vector.
 * Return: Always 0.
 */
int main(int argc, char *argv[])
{
	int fd, n_read;
	char sys;
	char buf[27]; /* this is sufficiant for needed info */

	if (argc != 2)
	{
		dprintf(STDERR_FILENO, "Usage: elf_header elf_filename\n");
		exit(98);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
	{
		dprintf(STDERR_FILENO, "Err: file can not be open\n");
		exit(98);
	}
	lseek(fd, 0, SEEK_SET); /*seek to the start of elf header*/
	/*read only the first 27 byte (until the entry address)*/
	n_read = read(fd, buf, 27);
	if (n_read == -1)
	{
		dprintf(STDERR_FILENO, "Err: The file can not be read\n");
		exit(98);
	}
	if (!check_elf(buf))
	{
		dprintf(STDERR_FILENO, "Err: It is not an ELF\n");
		exit(98);
	}
	sys = buf[4] + '0';
	if (sys == '0') /*class must be only 1 or 2*/
		exit(98);
	print_magic(buf);
	print_class(buf);
	print_data(buf);
	print_version(buf);
	print_osabi(buf);
	print_type(buf);
	print_addr(buf);
	close(fd);
	return (0);
}
