#include <stdio.h>
#include <stdlib.h>
/**
 * main -  prints the minimum number of coins to make change
 * for an amount of money.
 */
int main(int argc, char *argv[])
{
	int coins, cents;

	if (argc != 2)
	{
		printf("Error\n");
		return (1);
	}

	cents = atoi(argv[1]);
	if (cents < 0)
	{
		printf("0\n");
		return (0);
	}

	coins = 0;
	while (cents >= 25)
	{
		coins++;
		cents -= 25;
	}

	while (cents >= 10)
	{
		coins++;
		cents -= 10;
	}

	while (cents >= 5)
	{
		coins++;
		cents -= 5;
	}

	while (cents >= 2)
	{
		coins++;
		cents -= 2;
	}

	while (cents >= 1)
	{
		coins++;
		cents--;
	}
	printf("%d\n", coins);
}