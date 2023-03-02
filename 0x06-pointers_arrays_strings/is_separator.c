/**
 * is_separator - checks weather the character is a word separator
 * @ch: the character to be checked
 * Return: 1 if the char is separator, 0 otherwise.
 */
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