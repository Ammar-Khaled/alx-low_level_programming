#include <stdio.h>

/**
 * main -  print alphabet
 * Return: Always 0 (Success)
 */

int main(void)
{
char ch = 'a';
while (ch <= 'z')
{
	putchar(ch++);
}
ch = 'A';
while (ch <= 'Z')
{
	putchar(ch++);
}
putchar('\n');
return (0);
}
