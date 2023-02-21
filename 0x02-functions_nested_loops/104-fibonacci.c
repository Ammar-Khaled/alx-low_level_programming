#include <stdio.h>
/**
 * print_98_fib - prints the first 98 Fibonacci numbers, starting with 1 and 2, followed by a new line.
 */
void print_98_fib(void)
{
int n1 = 1, n2 = 2, n = n1 + n2;
printf("1, 2, ");
int i = 3;
while (i < 99)
{
	printf("%d, ", n);
	n1 = n2;
	n2 = n;
	n = n1 + n2;
	++i;
}
printf("\n");
}
