#include <stdio.h>

/**
 * main -  print alphabet
 * Return: Always 0 (Success)
 */

int main(void)
{
char ch = '0';
while (ch <= '9')
  putchar(ch++);
ch = 'a';  
while (ch <= 'f')
  putchar(ch++);
putchar('\n');
return (0);
}
