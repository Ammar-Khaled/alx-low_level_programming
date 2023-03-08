/**
 * factorial - computes the factorial of a given number.
 * @n: the number we need to compute its factorial
 * Return: n * (n - 1) * (n - 2) * ... * 2 * 1
 */
int factorial(int n)
{
	if (n < 0)
		return (-1);

	if (n <= 1)
		return (1);

	return (n * factorial(n - 1));
}
