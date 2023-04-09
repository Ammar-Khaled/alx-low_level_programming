#include "main.h"
#include <stdio.h>

/**
 * main - copies the content of a file to another file.
 * @argc: number of arguments.
 * @argv: arguments vector.
 *
 * Return: Always 0 (Success).
 */
int main(int argc, char *argv[])
{
	int fd1, fd2;
	char *buf;

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		return (97);
	}

	fd1 = open(argv[1], O_RDONLY);
	if (fd1 == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
		return (98);
	}

	fd2 = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);
	if (fd1 == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
		return (99);
	}

	buf = malloc(sizeof(char) * 1024);
	if (!buf)
		return (100);

	read(fd1, buf, 1024);
	write(fd2, buf, 1024);

	if (close(fd1) == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %i\n", fd1);
		return (100);
	}

	if (close(fd2) == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %i\n", fd2);
		return (100);
	}
	return (0);
}
