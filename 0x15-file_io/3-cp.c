#include "main.h"
#include <stdio.h>

/**
 * print_file_error - checks if files can be opened.
 * @file_from_fd: file_from.
 * @file_to_fd: file_to.
 * @argv: arguments vector.
 * Return: no return.
 */
void print_file_error(int file_from_fd, int file_to_fd, char *argv[])
{
	if (file_from_fd == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
		exit(98);
	}
	if (file_to_fd == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
		exit(99);
	}
}

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
	char buf[1024];
	ssize_t nchars, nwritten;

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		return (97);
	}
	fd1 = open(argv[1], O_RDONLY);
	fd2 = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);
	print_file_error(fd1, fd2, argv);
	nchars = 1024;
	while (nchars == 1024)
	{
		nchars = read(fd1, buf, 1024);
		if (nchars == -1)
			print_file_error(-1, 0, argv);
		nwritten = write(fd2, buf, nchars);
		if (nwritten == -1)
			print_file_error(0, -1, argv);
	}

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
