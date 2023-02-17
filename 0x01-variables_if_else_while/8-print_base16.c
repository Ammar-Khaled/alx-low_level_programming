#include <stdio.h>

/**
 * main -  print
 * Return: Always 0
 */

int main(void)
{
char ch;
ch = '0';
while (ch <= '9')
{
	putchar(ch++);
}
ch = 'a';  
while (ch <= 'f')
{
	putchar(ch++);
}
putchar('\n');
return (0);
}
