#include <stdio.h>
/**
 * main - finds and prints the largest prime factor of
 * the number 612852475143, followed by a new line.
 *
 * Return: Always 0.
 */
int main(void)
{
	int max = 0, i;
	long n;

	n = 612852475143;
	while (n > 1)
	{
		if (n % 2 == 0)
		{
			n /= 2;
			max = (max < 2) ? 2 : max;
		}
		else
		{
			for (i = 3; i <= n; i += 2)
			{
				if (n % i == 0)
				{
				n /= i;
				max = (i > max) ? i : max;
				break;
				}
			}
		}

	}
	printf("%d\n", max);
	return (0);
}
