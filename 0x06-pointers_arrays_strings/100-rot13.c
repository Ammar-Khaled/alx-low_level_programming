
/**
 * rot13 - encodes a string using rot13 algorithm
 * @s: string to be encoed
 * Return: pointer to the resulting encoded string
 */
char *rot13(char *s)
{
	int i, indx;
	char alphabet[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm',
			   'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M',
			   'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
			   'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
	for (i = 0; s[i] != '\0'; i++)
	{
		if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z'))
		{
			for (indx = 0; indx < 52; indx++)
			{
				if (s[i] == alphabet[indx])
					break;
			}
			s[i] = alphabet[(indx + 26) % 52];
		}
	}
	return (s);
}