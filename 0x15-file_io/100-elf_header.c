/**
 * read_header - check the version system.
 * @ptr: magic.
 * Return: no return.
 */
void read_header(char *ptr)
{

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
		exit (98);
	}

	lseek(fd, 0, SEEKSET);
	if (read(fd, buf, 27) == -1)
	{
		dprintf(STDERR_FILENO, "Err: The file can not be read\n");
		exit (98);
	}

	if (check_elf(buf) == 0)
	{
		dprintf(STDERR_FILENO, "Error: not an ELF\n");
		exit (98);
	}
	
	read_header(buf);
	close(fd);

	return (0);
}
