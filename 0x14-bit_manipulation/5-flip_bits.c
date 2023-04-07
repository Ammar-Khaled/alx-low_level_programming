
/**
 * flip_bits - finds the number of bits you would need to flip
 * to get from one number to another.
 * @n: a number
 * @m: another number
 *
 * Return: number of bits you would need to flip
 */
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	int i, count;

	n ^= m;
	count = 0;
	for (i = 0; i < 64 && n; i++)
	{
		count  += (n & 1);
		n >>= 1;
	}

	return (count);
}
