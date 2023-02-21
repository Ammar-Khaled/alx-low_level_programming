#include "main.h"
/**
 * print_last_digit -  prints the last digit of a number.
 * @n: the number
 * Return: the value of the last digit
 */
int print_last_digit(int n)
{
int digit;
  
digit = n % 10;
_putchar(digit);
return digit;
}
