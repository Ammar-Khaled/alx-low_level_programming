#include <stdio.h>

/**
 * main -  print alphabet
 * Return: Always 0 (Success)
 */

int main(void)
{
for (int i = 0; i < 10; i++)
{
  putchar('0'+i);
  putchar(',');
  if (i != 9) putchar(' ');
}  
return (0);
}
