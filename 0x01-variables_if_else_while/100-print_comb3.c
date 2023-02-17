#include <stdio.h>

/**
 * main -  print  all possible different combinations of two digits
 * Return: Always 0 (Success)
 */

int main(void)
{

for (int i = 48; i < 58; i++)
{
  for (int j = i+1; j < 58; j++)
  {
   putchar(i); putchar(j); putchar(',');
   if ( i != 56 && j != 57)
     putchar(' '); 
     
  }
}  
putchar('\n');
return (0);
}
