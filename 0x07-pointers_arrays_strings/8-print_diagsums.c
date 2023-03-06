#include <stdio.h>

/**
 * print_diagsums - prints the sum of the two diagonals of
 * a square matrix of integers.
 * @a: pointer to the matrix
 * @size: the dimension of the matrix
 */
void print_diagsums(int *a, int size)
{
	int i, j, diagsum;

	i = j = diagsum = 0;
	while (i < size && j < size)
	{
		diagsum += a[i * size + j];
		i++;
		j++;
	}

	printf("%d, ", diagsum);

	i = diagsum = 0;
	j = size - 1;
	while (i < size && j > -1)
	{
		diagsum += a[i * size + j];
		i++;
		j--;
	}
	printf("%d\n", diagsum);
}
