#include <stdio.h>

/**
 * main -  print alphabet reversily
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
