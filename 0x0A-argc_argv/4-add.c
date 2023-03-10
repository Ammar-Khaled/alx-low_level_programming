#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/**
 * main - adds positive numbers.
 * @argc: number of command line arguments passed to main
 * @argv: vector of command line arguments passed to main
 * Return: 0 if success , 1 otherwise
 */
int main(int argc, char *argv[])
{
	int sum, i;
	size_t j;

	if (argc == 1)
	{
		printf("0\n");
		return (0);
	}

	sum = 0;
	for (i = 1; i < argc; i++)
	{
		for (j = 0; j < strlen(argv[i]); j++)
		{
			if (argv[i][j] < '0' || argv[i][j] > '9')
			{
				printf("Error\n");
				return (1);
			}
		}

		sum += atoi(argv[i]);
	}
	printf("%d\n", sum);
	return (0);
}
