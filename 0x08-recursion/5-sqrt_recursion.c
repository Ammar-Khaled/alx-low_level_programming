
int try(int n, int k)
{
	if (k * k >= n)
		return k;

	try(n, k + 1);
}
/**
 * _sqrt_recursion - returns the natural square root of a number.
 * @n: the desired number
 * Return: square root of a n
 */
int _sqrt_recursion(int n)
{
	if (n < 0)
		return (-1);
	if (n <= 1)
		return (n);
	return (try(n, 2));
}