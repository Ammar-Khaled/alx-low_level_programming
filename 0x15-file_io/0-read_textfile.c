#include "main.h"

/**
 * read_textfile - reads a text file and prints it to the POSIX standard output
 * @filename: file name
 * @letters: the number of letters to read and print
 *
 * Return: the actual number of letters it could read and print, or 0 otherwise
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	int fd;
	char *buf;
	ssize_t read_count, write_count;

	if (!filename)
		return (0);

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (0);

	buf = malloc(sizeof(char) * letters);
	if (!buf)
		return (0);

	read_count = read(fd, buf, letters);
	write_count = write(STDOUT_FILENO, buf, read_count);


	close(fd);
	free(buf);
	return (write_count);
}
