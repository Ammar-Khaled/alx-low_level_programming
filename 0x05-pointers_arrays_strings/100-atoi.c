/**
 * _isdigit - checks for a digit (0 through 9).
 * @c: the digit to be checked
 * Return: 1 if c is a digit and 0 otherwise.
 */
int _isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

int _atoi(char *s)
{
	int ans, negatives, i;

	ans = i = negatives =0;
	while (s[i] != '\0')
	{
		if (s[i] == '-')
		{
			negatives++;
			continue;
		}
		else if (!_isdigit(s[i]))
		{
			continue;
		}

		ans *= 10;
		ans += s[i] - '0';
	}
	return (ans);
}
