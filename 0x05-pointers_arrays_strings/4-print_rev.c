#include "main.h"
/**
 * _strlen - computes the length of a string.
 * @s: pointer to string.
 * Return: How many characters the string contains.
 */
int _strlen(char *s)
{
        int i;

        i = 0;
        while (s[i] != '\0')
        {
                i++;
        }

        return (i);
}

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
