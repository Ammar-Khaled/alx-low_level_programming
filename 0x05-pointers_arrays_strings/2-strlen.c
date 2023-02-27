/**
 * _strlen - computes the length of a string.
 * @s: pointer to string.
 * Return: How many characters the string contains.
 */
int _strlen(char *s)
{
int i;

i = 0;
while (s[i] != '\0')
{
    i++;
}

return (i);
}
