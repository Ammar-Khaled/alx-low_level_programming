/**
 * try - find the square of numbers from 2 to N,
 *  till the square of some number K becomes greater than or equal N.
 *  Hence the value of K will be the floor square root of N.
 * @n: number we mant to find its sqr
 * @k: cuurent test number
 * Return: the floor integer value of square root of n;
 */
int try(int n, int k)
{
	if (k * k >= n)
		return (k);

	return (try(n, k + 1));
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
