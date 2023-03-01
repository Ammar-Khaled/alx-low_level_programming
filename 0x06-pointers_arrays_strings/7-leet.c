
/**
 * leet - encodes a string into 1337.
 * @s: string to be encoded
 * Return: pointer to the resulting string
 */
char *leet(char *s)
{
	char letters[] = {'a', 'e', 'o', 't', 'l', 'A', 'E', 'O', 'T', 'L'};
	char digits[] = {'4', '3', '0', '7', '1'};
	int i, j;

	for (i = 0; s[i] != '\0'; i++)
	{
		for (j = 0; j < 10; j++)
		{
			if (s[i] == letters[j] || s[i] == letters[j + 5])
				s[i] = digits[j % 5];
		}
	}

	return (s);
}
