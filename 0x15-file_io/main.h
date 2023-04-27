#ifndef MAIN_H
#define MAIN_H

#include <sys/types.h>	/* for ssize_t */
#include <sys/stat.h>
#include <fcntl.h>/* for open() and O_RDWR */
#include <unistd.h>/* for read(), write(), and close() */
#include <stdlib.h>	/* for size_t */

ssize_t read_textfile(const char *filename, size_t letters);
int create_file(const char *filename, char *text_content);
int append_text_to_file(const char *filename, char *text_content);

#endif
