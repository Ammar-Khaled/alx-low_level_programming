#include <stdlib.h>
/**
 * alloc_grid - creates a 2 dimensional array of integers initialised to 0.
 * @width: number of columns
 * @height: number of rows
 * Return: a pointer to the 2D array, NULL if failure
 */
int **alloc_grid(int width, int height)
{
	int **p, i, j;

	if (width <= 0 || height <= 0)
		return (NULL);

	p = malloc(width * sizeof(int *));
	if (p == NULL)
		return (NULL);

	for (i = 0; i < width; i++)
	{
		p[i] = malloc(height * sizeof(int));
		if (p[i] == NULL)
		{
			free(p);
			return (NULL);
		}
	}

	for (i = 0; i < width; i++)
		for (j = 0; j < height; j++)
			p[i][j] = 0;

	return (p);
}
