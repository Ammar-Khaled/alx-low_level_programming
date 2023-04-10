#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <elf.h>

/**
 * print_addr - prints address of the entry point
 * @ptr: magic.
 * Return: no return.
 */
void print_addr(char *ptr)
{
	int i, begin;
	char sys;

	printf("  Entry point address:               0x");
	sys = ptr[4];
	if (sys == 1)/*32-bit*/
	{
		begin = 26;
		printf("80");
		for (i = begin; i > 21; i--)
		{
			if (ptr[i] > 0)
				printf("%x", ptr[i]);
			else if (ptr[i] < 0)
				printf("%x", ptr[i] + 256);
		}
		if (ptr[7] == 6)
			printf("00");
	}

	if (sys == 2)
	{
		begin = 26;
		for (i = begin; i > 23; i--)
		{
			if (ptr[i] > 0)
				printf("%x", ptr[i]);
			else if (ptr[i] < 0)
				printf("%x", ptr[i] + 256);
		}
	}

	printf("\n");
}
/**
 * print_type - prints type
 * @ptr: magic.
 * Return: no return.
 */
void print_type(char *ptr)
{
	char type;

	if (ptr[5] == 1)
		type = ptr[16];
	else
		type = ptr[17];

	printf("  Type:                              ");
	switch (type)
	{
	case 0:
		printf("NONE (No file type)\n");
		break;
	case 1:
		printf("REL (Relocatable file)\n");
		break;
	case 2:
		printf("EXEC (Executable file)\n");
		break;
	case 3:
		printf("DYN (Shared object file)\n");
		break;
	case 4:
		printf("CORE (Core file)\n");
		break;
	default:
		printf("<unknown: %x>\n", type);
		break;
	}
}

/**
 * print_osabi - prints osabi
 * @ptr: magic.
 * Return: no return.
 */
void print_osabi(char *ptr)
{
	char osabi;

	osabi = ptr[7];
	printf("  OS/ABI:                            ");
	switch (osabi)
	{
	case 0:
		printf("UNIX - System V\n");
		break;
	case 2:
		printf("UNIX - NetBSD\n");
		break;
	case 3:
		printf("UNIX - Solaris\n");
		break;
	default:
		printf("<unknown: %x>\n", osabi);
		break;
	}

	printf("  ABI Version:                       %d\n", ptr[8]);
}
/**
 * print_version - prints version
 * @ptr: magic.
 * Return: no return.
 */
void print_version(char *ptr)
{
	int version;

	version = ptr[6];
	printf("  Version:                           %d", version);
	if (version == EV_CURRENT)
		printf(" (current)");
	printf("\n");
}

/**
 * print_data - prints data
 * @ptr: magic.
 * Return: no return.
 */
void print_data(char *ptr)
{
	char data;

	data = ptr[5];
	printf("  Data:                              2's complement");
	if (data == 1)
		printf(", little endian\n");
	else if (data == 2)
		printf(", big endian\n");
}

/**
 * print_magic - prints magic info.
 * @ptr: magic.
 * Return: no return.
 */
void print_magic(char *ptr)
{
	int i;

	printf("  Magic:  ");
	for (i = 0; i < 16; i++)
	{
		printf("%02x ", ptr[i]);
	}
	printf("\n");
}

/**
 * read_header -displays the header information of elf file
 * @ptr: magic.
 * Return: no return.
 */
void read_header(char *ptr)
{

	char class;

	class = ptr[4];
	if (class == 0)
		exit(98);

	printf("ELF Header:\n");
	print_magic(ptr);

	if (class == 1)
	{
		printf("  Class:                             ELF32\n");
	}
	else if (class == 2)
	{
		printf("  Class:                             ELF64\n");
	}
	print_data(ptr);
	print_version(ptr);
	print_osabi(ptr);
	print_type(ptr);
	print_addr(ptr);
}

/**
 * check_elf - check if it is an elf file.
 * @ptr: magic.
 * Return: 1 if it is an elf file. 0 if not.
 */
int check_elf(char *ptr)
{
	if ((int)ptr[0] == 127 && ptr[1] == 'E' && ptr[2] == 'L' && ptr[3] == 'F')
		return (1);
	return (0);
}

/**
 * main - displays elf header
 * @argc: number of arguments.
 * @argv: arguments vector.
 * Return: Always 0. (Success)
 */
int main(int argc, char *argv[])
{
	int fd;
	char buf[27];

	if (argc != 2)
	{
		dprintf(STDERR_FILENO, "Usage: elf_header elf_filename\n");
		exit(98);
	}

	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		dprintf(STDERR_FILENO, "Err: file can not be open\n");
		exit(98);
	}

	lseek(fd, 0, SEEK_SET);
	if (read(fd, buf, 27) == -1)
	{
		dprintf(STDERR_FILENO, "Err: The file can not be read\n");
		exit(98);
	}

	if (check_elf(buf) == 0)
	{
		dprintf(STDERR_FILENO, "Error: not an ELF\n");
		exit(98);
	}

	read_header(buf);
	close(fd);

	return (0);
}
