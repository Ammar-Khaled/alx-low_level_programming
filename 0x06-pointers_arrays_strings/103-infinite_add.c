#include <string.h>
char *infinite_add(char *n1, char *n2, char *r, int size_r)
{
	int len1, len2, carry, i, max_len, *ip;
	
	ip = &carry;
	len1 = strlen(n1) - 1;
	len2 = strlen(n2) - 1;
	a1 += strlen(n1) - 1;
	a2 += strlen(n2) - 1;
	
	max_len = len1 >= len2 ? len1 : len2;
	carry = 0;

	if (size_r < max_len)
		return 0;
	
	char* tmp;
	tmp = r;
	do{
	    addnums(n1,n2,tmp,ip) ;
	    tmp++;
	    len1--;len2--;   
	    if (len1!=-1 && len2!=-1) n1-- ,n2--;
	}while(len1>-1 && len2>-1) ;
	
	void addnums(char *n1, char *n2, char *r, int *ip){
	*r++ = (char)((*a1 - '0' + *a2 - '0' + *ip) % 10 + '0');
	*ip = (*a1 - '0' + *a2 - '0' + *ip) / 10;
	}
	
	/*
	for (i = max_len; i >= 0; i--)
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
	*/
	if (carry && size_r < max_len + 1)
		return 0;
	else if (carry)
		r[i] = '1';
	
	return (r);
}
