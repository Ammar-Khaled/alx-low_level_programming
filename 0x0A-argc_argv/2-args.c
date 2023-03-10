#include <stdio.h>
/**
 * main - prints all arguments it receives.
 * @argc: number of command line arguments passed to main
 * @argv: vector of command line arguments passed to main
 * Return: 0
 */
int main(int argc, char *argv[])
{
	int i;
	for (i = 0; i < argc; i++)
		printf("%s\n", argv[i]);
	return (0);
}
