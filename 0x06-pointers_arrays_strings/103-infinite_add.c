#include <string.h>
char *infinite_add(char *n1, char *n2, char *r, int size_r)
{
	int len1, len2, carry, i, max_len;

	len1 = strlen(n1);
	len2 = strlen(n2);
	max_len = len1 >= len2 ? len1 : len2;
	carry = 0;

	if (size_r < max_len)
		return 0;

	for (i = 0; i < max_len; i++)
	{
		if (len1 && len2)
		{
			r[i] = (((n1[i] - '0') + (n2[i] - '0') + carry) % 10 ) + '0';
			carry = (((n1[i] - '0') + (n2[i] - '0') + carry) / 10 );
		}
		else if (len1)
		{
			r[i] = (((n1[i] - '0') + carry) % 10 ) + '0';
			carry = (((n1[i] - '0') + carry) / 10 );
		}
		else if (len2)
		{
			r[i] = (((n2[i] - '0') + carry) % 10 ) + '0';
                        carry = (((n2[i] - '0') + carry) / 10 );
		}
		len1--;
		len2--;
	}

	if (carry && size_r < max_len + 1)
		return 0;
	else if (carry)
		r[i] = '1';
	
	return (r);
}
