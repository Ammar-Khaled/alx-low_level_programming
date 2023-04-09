#include "main.h"

/**
 * append_text_to_file - append text to file
 * @filename: filename.
 * @text_content: content appended to the file.
 *
 * Return: 1 if it success. -1 if it fails.
 */
int append_text_to_file(const char *filename, char *text_content)
{
	int fd, n;

	if (!filename)
		return (-1);

	if (!text_content)
		text_content = "";

	fd = open(filename, O_WRONLY | O_APPEND);
	if (fd == -1)
		return (-1);

	for (n = 0; text_content[n]; n++)
		;

	n = write(fd, text_content, n);
	if (n == -1)
		return (-1);

	close(fd);
	return (1);
}
