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

	ans = 0;
	i = 0;
	negatives = 0;
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
	if (negatives % 2 == 1)
		return (-1 * ans);
	return (ans);
}
