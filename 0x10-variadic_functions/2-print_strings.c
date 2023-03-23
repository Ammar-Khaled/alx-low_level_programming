#include <stdio.h>
#include <stdarg.h>
/**
 * print_strings - prints strings, followed by a new line.
 * @separator: the string to be printed between strings
 * @n: the number of strings passed to the function
 */
void print_strings(const char *separator, const unsigned int n, ...)
{
	va_list args;
	unsigned int i;
	char *s;

	va_start(args, n);
	for (i = 0; i < n; i++)
	{
		s = va_arg(args, char *);
		if (s)
			printf("%s", s);
		else
			printf("(nil)");
			
		if (i == n - 1)
			printf("\n");
		else if (separator)
			printf("%s", separator);
	}
	va_end(args);
}
