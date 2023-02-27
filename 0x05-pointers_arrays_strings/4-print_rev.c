#include "main.h"
/**
 * print_rev -  prints a string, in reverse, followed by a new line.
 * @s: pointer to the string
 */
void print_rev(char *s)
{
int i;

for (i = _strlen(s) - 1; i > -1; i--)
{
        _putchar(s[i]);
}
_putchar('\n');
}
