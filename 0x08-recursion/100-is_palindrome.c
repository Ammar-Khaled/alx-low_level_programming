#include <string.h>


int is_palindrome(char *s, int len)
{
	if (len <= 1)
		return 1;
	return s[0] == s[len - 1] && is_palindrome(s + 1, len - 2);
}
