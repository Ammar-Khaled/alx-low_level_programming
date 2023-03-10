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

/**
 * _atoi -  convert a string to an integer.
 * @s: string to be converted
 * Return: integer representation of the string
 */
int _atoi(char *s)
{
	unsigned int ans, negatives, i, flag;

	ans = 0;
	i = 0;
	negatives = 0;
	flag = 0;
	while (s[i] != '\0')
	{
		if (s[i] == '-')
		{
			if (flag)
				break;
			negatives++;
			i++;
			continue;
		}
		else if (!_isdigit(s[i]))
		{
			if (flag)
				break;
			i++;
			continue;
		}
		flag = 1;
		ans *= 10;
		ans += s[i] - '0';
		i++;
	}
	if (negatives % 2 == 1)
		return (-1 * ans);
	return (ans);
}
