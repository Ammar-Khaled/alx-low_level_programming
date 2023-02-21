#include <stdio.h>

/** print_50_fib - prints the first 50 Fibonacci numbers, starting with 1 and 2, followed by a new line.
 */
void print_50_fib()
{
int fib[51];
printf("%d, %d, ", 1, 2);
fib[1] = 1;
fib[2] = 2;
int i = 3;
while (i < 51)
{
	fib[i] = fib[i - 1] + fib[i - 2];
	printf("%d, ", fib[i]);
}
printf("\n");
}
