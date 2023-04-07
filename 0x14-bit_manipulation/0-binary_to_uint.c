
/**
 * binary_to_uint - converts a binary number to an unsigned int.
 * @b: pointer to a string of 0 and 1 chars
 *
 * Return: the converted number, or 0 if
 * *there is one or more chars in the string b that is not 0 or 1
 * *b is NULL
 */
unsigned int binary_to_uint(const char *b)
{
	int i, place_value;
	unsigned int ans;

	if (!b)
		return (0);

	for (i = 0; b[i]; i++)
		;

	i--;
	place_value = 1;
	ans = 0;
	while (i > -1)
	{
		if ((b[i] - '0') > 9 || (b[i] - '0') < 0)
			return (0);

		ans += (b[i] - '0') * place_value;
		i--;
		place_value *= 2;
	}

	return (ans);
}
