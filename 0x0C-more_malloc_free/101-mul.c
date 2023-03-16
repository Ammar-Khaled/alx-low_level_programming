#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/**
 * print_error - indicates errors happening
 */
void print_error(void)
{
	printf("Error\n");
	exit(98);
}

/**
 * validate_num - checks that num consists of digits only
 * @num: the number to be validated
 * Return: exits the program if num is not valid
 */
void validate_num(char *num)
{
	int i, len;

	len = strlen(num);
	for (i = 0; i < len; i++)
	{
		if (!isdigit(num[i]))
			print_error();
	}
}

/**
 * print_result - prints the product
 * @result: pointer to the result
 */
void print_result(char *result)
{
	int i;

	for (i = 0; result[i] != '\0'; i++)
		_putchar(result[i]);
	_putchar('\n');
}
/**
 * main - multiplies two positive numbers.
 * @argc: arguments count
 * @argv: arguments vector
 * Return: 0 (success), or 98 (Error)
 */
int main(int argc, char *argv[])
{
	int i, j, carry, product, sum, len1, len2, len3;
	char *result;

	if (argc != 3)
		print_error();
	len1 = strlen(argv[1]);
	len2 = strlen(argv[2]);
	len3 = len1 + len2;
	validate_num(argv[1]);
	validate_num(argv[2]);
	for (i = 0; i < len2; i++)
		if (!isdigit(argv[2][i]))
			print_error();
	result = (char *)malloc(len3 + 1);
	if (!result)
		print_error();
	memset(result, '0', len3);
	result[len3] = '\0';
	for (i = len1 - 1; i >= 0; i--)
	{
		carry = 0;
		for (j = len2 - 1; j >= 0; j--)
		{
			product = (argv[1][i] - '0') * (argv[2][j] - '0');
			sum = result[i + j + 1] - '0' + product + carry;
			result[i + j + 1] = sum % 10 + '0';
			carry = sum / 10;
		}
		result[i] += carry;
	}
	for (i = 0; i < len3 - 1 && result[i] == '0'; i++)
		;
	if (i > 0)
	{
		memmove(result, result + i, len3 - i);
		result[len3 - i] = '\0';
	}
	print_result(result);
	free(result);
	return (0);
}
