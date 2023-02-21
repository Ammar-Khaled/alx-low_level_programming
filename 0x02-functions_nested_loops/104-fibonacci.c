#include <stdio.h>
/**
 * main - prints the first 98 Fibonacci numbers,
 * starting with 1 and 2, followed by a new line.
 * Return: Always 0
 */
int main(void)
{
long n1, n2, n, i;

n1 = 1;
n2 = 2;
printf("1, 2, ");
i = 3;
while (i < 99)
{
	n = n1 + n2;
	printf("%ld", n);
	n1 = n2;
	n2 = n;
	if (i != 98)
		printf(", ");
	else
		printf("\n");
	++i;
}

return (0);
}
