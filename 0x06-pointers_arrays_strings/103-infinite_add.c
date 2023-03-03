#include <string.h>

#include "main.h"

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

/**
 * rev_string - reverses a string.
 * @s: pointer to the string
 */
void rev_string(char *s)
{
	int len, i, j;
	char tmp;

	len = _strlen(s);
	i = 0;
	j = len - 1;
	while (i <= j)
	{
		tmp = s[j];
		s[j] = s[i];
		s[i] = tmp;
		i++;
		j--;
	}
}

void swap(char *str1, char *str2)
{
char *temp = str1;
str1 = str2;
str2 = temp;
}

char *infinite_add(char *n1, char *n2, char *r, int size_r)
{
	
	int i, len1, len2, carry;

	if (strlen(n1) > strlen(n2))
		swap(n1, n2);

	if (size_r < (int)strlen(n2))
		return 0;


	len1 = strlen(n1);
	len2 = strlen(n2);
	strrev(n1);
	strrev(n2);
	
	carry = 0;
	

	for (i = 0; i < len1; i++)
	{
		r[i] = (((n1[i] - '0') + (n2[i] - '0') + carry) % 10 ) + '0';	
		carry = (((n1[i] - '0') + (n2[i] - '0') + carry) / 10 );
	}

	for (; i < len2; i++)
	{
		r[i] = (((n2[i] - '0') + carry) % 10 ) + '0';
		carry = (((n2[i] - '0') + carry) / 10 );
	}

	if (carry && size_r < (int)strlen(n2) + 1)
		return 0;
	else if (carry)
		r[i] = carry + '0';
	strrev(r);
	return (r);
}
