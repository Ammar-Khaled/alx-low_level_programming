
/**
 * set_string - sets the value of a pointer to a char.
 * @s: pointer to the pointer to the string to be set
 * @to: pointer to the string to set
 */
void set_string(char **s, char *to)
{
	while (**s != '\0')
	{
		if (*to != '\0')
		{
			**s = *to;
			to++;
			(*s)++;
		}
		else
		{
			**s = '\0';
			return;
		}
	}
}