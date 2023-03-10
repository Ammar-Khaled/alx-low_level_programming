#include <stdio.h>
/**
 * main - prints the name of the program
 * @argc: number of command line arguments passed to main
 * @argv: vector of command line arguments passed to main
 * Return: 0
 */
int main(int argc, char *argv[])
{
	if (argc == 1)
		printf("%s\n", argv[0]);
	return (0);
}
