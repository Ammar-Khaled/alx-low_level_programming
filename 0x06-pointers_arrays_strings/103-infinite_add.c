#include <string.h>
char *infinite_add(char *n1, char *n2, char *r, int size_r)
{
	int len1, len2, carry, max_len;
	len1 = strlen(n1);
	len2 = strlen(n2);
	n1 += strlen(n1) - 1;
	n2 += strlen(n2) - 1;
	
	max_len = len1 >= len2 ? len1 : len2;
	carry = 0;
	r += max_len - 1;

	if (size_r < max_len)
		return 0;

	while (len1 > -1 || len2 > -1)
	{
		if (len1 && len2)
		{
			*r = (((*n1 - '0') + (*n2 - '0') + carry) % 10 ) + '0';
			carry = (((*n1 - '0') + (*n2 - '0') + carry) / 10 );
		}
		else if (len1)
		{
			*r = (((*n1 - '0') + carry) % 10 ) + '0';
			carry = (((*n1 - '0') + carry) / 10 );
		}
		else if (len2)
		{
			*r = (((*n2 - '0') + carry) % 10 ) + '0';
                        carry = (((*n2 - '0') + carry) / 10 );
		}
		len1--;
		len2--;
		n1--;
		n2--;
		r--;
	}

	if (carry && size_r < max_len + 1)
		return 0;
	else if (carry)
		*r = '1';
	
	return (r);
}
