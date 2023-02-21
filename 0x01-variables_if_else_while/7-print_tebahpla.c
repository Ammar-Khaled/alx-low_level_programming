#include <stdio.h>

/**
 * main -  print
 * Return: Always 0
 */

int main(void)
{
char ch;
ch = 'z';
while (ch >= 'a')
{
	putchar(ch--);
}
putchar('\n');
return (0);
}
