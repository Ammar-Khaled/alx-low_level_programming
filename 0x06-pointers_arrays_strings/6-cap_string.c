
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

int _isalpha(char ch)
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

	int i, new_word;

	new_word = 1;
	for (i = 0; s[i] != '\0'; i++)
	{
		if (new_word)
		{
			new_word = 0;
			if (s[i] >= 'a' && s[i] <= 'z')
				s[i] -= 32;
		}
		if (_isalpha(s[i + 1]) && is_separator(s[i]))
			new_word = 1;
	}
	return (s);
}
