#include <stdio.h>
/**
 * main - finds and prints the largest prime factor of
 * the number 612852475143, followed by a new line.
 *
 * Return: Always 0.
 */
int main(void)
{
	int max, n, i;

	n = 612852475143;
	while (n > 1)
	{
		if (n % 2 == 0)
			i = 2;
		else
		{
		for (i = 2; i <= n; i++)
		{
			n /= i;
			max = i > max? i : max;
			break;	
		}}

	}
	printf("%d", max);
	return (0);
}
