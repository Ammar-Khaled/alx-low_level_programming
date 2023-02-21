#include <stdio.h>

/** - computes and prints the sum of all the multiples of 3 or 5 below 1024 (excluded), followed by a new line.
 */
void multiples(void)
{
	int sum = 0;
	int n = 3;
	int factor = 2;
	while (n < 1024)
	{
		sum += n;
		n *= factor;
		factor++;
	}
	n = 5;
	factor = 2;
	while (n < 1024)
	{
		sum += n;
		n *= factor;
		factor++;
	}
	printf("%d\n", sum);
}
