#include <stdarg.h>
/**
 * sum_them_all - sum all of its parameters.
 * @n: number of parameters
 *
 * Return: sum all of its parameters.
 */
int sum_them_all(const unsigned int n, ...)
{
	int sum;
	unsigned int i;
	va_list args;

	if (n == 0)
		return (0);

	va_start(args, n);
	
	sum = 0;
	for (i = 0; i < n; i++)
		sum += va_arg(args, int);
	
	va_end(args);

	return (sum);
}
