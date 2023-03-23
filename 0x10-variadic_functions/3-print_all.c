#include <stdio.h>
#include <stdarg.h>

/**
 * print_all - prints anything.
 * @format: a list of types of arguments passed to the function
 * c: char
 * i: integer
 * f: float
 * s: char * (if the string is NULL, print (nil) instead)
 * any other char is ignored
 */
void print_all(const char *const format, ...)
{
	va_list args;
	int i, first_printed;
	char *s;

	va_start(args, format);
	i = 0;
	first_printed = 0;
	/* print first arg */
	while (format[i] != '\0' && !first_printed)
	{
		switch (format[i])
		{
		case 'c':
			first_printed = 1;
			printf("%c", va_arg(args, int));
			break;
		case 'i':
			first_printed = 1;
			printf("%i", va_arg(args, int));
			break;
		case 'f':
			first_printed = 1;
			printf("%f", va_arg(args, double));
			break;
		case 's':
			first_printed = 1;
			s = va_arg(args, char*);
			if (s)
				printf("%s", s);
			else
				printf("(nil)");
			break;
		default:
			break;
		}
		i++;
	}

	while (format[i] != '\0')
	{
		switch (format[i])
		{
		case 'c':
			printf(", %c", va_arg(args, int));
			break;
		case 'i':
			printf(", %i", va_arg(args, int));
			break;
		case 'f':
			printf(", %f", va_arg(args, double));
			break;
		case 's':
			s = va_arg(args, char *);
			if (s)
				printf(", %s", s);
			else
				printf(", (nil)");
			break;
		default:
			break;
		}
		i++;
	}

	va_end(args);
	printf("\n");
}
