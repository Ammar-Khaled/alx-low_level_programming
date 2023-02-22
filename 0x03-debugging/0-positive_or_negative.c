#include <stdio.h>

/**
 * positive_or_negative -  print whether the number stored in the variable n
 * is positive or negative or zero.
 * Return: Always 0 (Success)
 */

void positive_or_negative(int n)
{
if (n > 0)
{
	printf("%i is positive\n", n);
}
else if (n < 0)
{
	printf("%i is negative\n", n);
}
else
{
	printf("%i is zero\n", n);
}

}
