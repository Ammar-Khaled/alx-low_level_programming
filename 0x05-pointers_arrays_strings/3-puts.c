#include "main.h"
/**
 * _puts - prints a string, followed by a new line, to stdout.
 * @str: pointer to string
 * Return: void
 */
void _puts(char *str)
{
while (*str != '\0')
{
_putchar(*str);
str++;
}
}
