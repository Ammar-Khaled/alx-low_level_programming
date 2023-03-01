int is_separator(char ch)
{
	char separators[] = {' ', '\t', '\n', ',', ';', '.',
			     '!', '?', '\"', '(', ')', '{', '}'};
	int i;

	for (i = 0; i < 13; i++)
	{
		if (ch == separators[i])
			return (1);
	}

	return (0);
}

int isalpha(char ch)
{
	return ((ch >= 65 && ch <= 90) || (ch >= 97 && ch <= 122));
}

/**
 * cap_string - capitalizes all words of a string.
 * @s: pointer to the string
 * Return: pointer to the resulting string
 */
char *cap_string(char *s)
{

	int i,
	    separated;

	separated = 1;
	for (i = 0; s[i] != '\0'; i++)
	{
		if (separated)
		{
			separated = 0;
			s[i] -= 32;
		}
	}
}