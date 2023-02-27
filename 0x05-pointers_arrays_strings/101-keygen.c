#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
/**
 * main - generates random password
 * generates random ascii codes that add up to 2772 to crack the program
 * Return: Always 0
 */
int main(void)
{
	int rand_num, sum;
	time_t t;
	
	rand_num = 0;
	sum = 0;
	srand((unsigned int) time(&t));
	
	while (sum < 2772)
	{
		rand_num = rand() % 128;
		if (sum + rand_num > 2772)
		{
			break;
		}
		sum += rand_num;
		printf("%c", rand_num);
	}
	printf("%c\n", 2772 - sum);
	return (0);
}
