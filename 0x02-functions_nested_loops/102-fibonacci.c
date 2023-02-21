#include <stdio.h>

/**
 * main - prints the first 50 Fibonacci numbers, starting with 1 and 2, followed by a new line.
 * Return: Always 0
 */
int main(void)
{
int fib[51], i;
printf("%d, %d, ", 1, 2);
fib[1] = 1;
fib[2] = 2;
i = 3;
while (i < 51)
{
	fib[i] = fib[i - 1] + fib[i - 2];
	fib[i - 2] = fib[i - 1];
	fib[i - 1] = fib[i];
	printf("%d, ", fib[i]);
}
printf("\n");
return (0);
}
