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
	
	sum = 0;
	srand(time(NULL) * getpid());
	while (sum < 2772)
	{
		rand_num = rand() % 256;
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
