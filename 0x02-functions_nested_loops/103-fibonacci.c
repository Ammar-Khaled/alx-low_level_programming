#include <stdio.h>

/**
 * main - considering the terms in the Fibonacci sequence
 * whose values do not exceed 4,000,000, write a program that
 * finds and prints the sum of the even-valued terms, followed by a new line.
 * Return: Always 0
 */
int main(void)
{
int n1 = 1, n2 = 2, n = n1 + n2;
long sum = 2;

while (n <= 4000000)
{
	if (n % 2 == 0)
	{
		sum += n;
	}
	n1 = n2;
	n2 = n;
	n = n1 + n2;
}
printf("%ld\n", sum);
return (0);
}
