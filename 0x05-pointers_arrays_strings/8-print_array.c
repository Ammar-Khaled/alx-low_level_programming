#include <stdio.h>

/**
 * print_array - prints elements of an array of integers.
 * @a: pointer to the array
 * @n: the number of elements of the array to be printed
 */
void print_array(int *a, int n)
{
	int i;

	for ( i = 0; n--; i++)
	{
		printf("%d", a[i]);
		if (n != 0)
			printf(", ");
	}
	printf("\n");
}
