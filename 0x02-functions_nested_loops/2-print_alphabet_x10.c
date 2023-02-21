#include "main.h"
/**
 * print_alphabet - print the alphabet, in lowercase, followed by a new line ten times.
 * Return: void
 */
void print_alphabet(void)
{
char ch = 'a';
int i = 0;
while (i < 10)
{
	while (ch <= 'z')
	{
		_putchar(ch);
	}
	_putchar('\n');
}
}
