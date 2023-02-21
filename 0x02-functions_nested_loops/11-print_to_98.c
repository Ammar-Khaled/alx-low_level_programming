#include <stdio.h>
/**
 * print_to_98 -  prints all natural numbers from n to 98, followed by a new line.
 */
void print_to_98(int n)
{
	while (n < 99)
	{
		printf("%d, ", n);
		n++;
	}
	printf("\n");
}
