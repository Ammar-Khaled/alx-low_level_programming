
/**
 * my_pow - find power using recursion
 * @x: the base
 * @y: the exponent
 * Return: the value of x raised to the power of y.
 */
int _pow_recursion(int x, int y)
{
	if (y == 0)
		return (1);
	return (x * my_pow(x, y - 1));
}
