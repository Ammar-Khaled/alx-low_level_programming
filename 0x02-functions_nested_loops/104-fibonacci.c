#include <stdio.h>
/**
 * main - prints the first 98 Fibonacci numbers,
 * starting with 1 and 2, followed by a new line.
 * Return: Always 0
 */
int main(void)
{
long double n1, n2, n, i;

n1 = 0;
n2 = 1;
i = 1;
while (i < 99)
{
	n = n1 + n2;
	printf("%.0g", n);
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
