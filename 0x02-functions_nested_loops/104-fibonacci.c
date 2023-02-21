#include <stdio.h>
/**
 * main - prints the first 98 Fibonacci numbers,
 * starting with 1 and 2, followed by a new line.
 * Return: Always 0
 */
int main(void)
{
/*the 98th Fibonacci number is 218 922 995 834 555 169 026 WHICH will cause overflow
*so we will divide it into low part (12 digits) and high part
*/
const unsigned long int half = 1000000000000;
unsigned long int n1_low, n1_high, n2_low, n2_high, sum_low, sum_high, i;

n1_low = n1_high = 0;
n2_low = 1;
n2_high = 0;
i = 1;
while (i < 99)
{
	/* sum = n1 + n2 */
	sum_low = n1_low + n2_low;
	sum_high = n1_high + n2_high;
	
	/* calculate and add carry to the high part*/
	sum_high += sum_low / half;
	
	/* remove carry from low part*/
	sum_low %= half;
	
	/* print sum*/
	if (sum_high > 0) {
        /* print higher half, then lower half*/
	printf("%lu%lu", sum_high, sum_low);
	}
	else
	{
        /* higher half is zero, so print lower half only */
        printf("%lu", sum_low);
	}
	
	n1_low = n2_low;
	n1_high = n2_high;
	
	n2_low = sum_low;
	n2_high = sum_high;
	
	if (i != 98)
		printf(", ");
	else
		printf("\n");
	++i;
}

return (0);
}
