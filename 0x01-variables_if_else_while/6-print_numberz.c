#include <stdio.h>

/**
 * main -  print  all single digit numbers
 * Return: Always 0 (Success)
 */

int main(void)
{
int ascii;
ascii = 48;
while (ascii <= 57)
{
	putchar(ascii++);
}
putchar('\n');
return (0);
}
