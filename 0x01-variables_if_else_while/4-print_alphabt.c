#include <stdio.h>

/**
 * main -  print alphabet
 * Return: Always 0 (Success)
 */

int main(void)
{
char ch = 'a';
for (; ch <= 'z' && ch != 'q' && ch != 'e'; ch++)
{  
	putchar(ch);
}
putchar('\n');
return (0);
}
