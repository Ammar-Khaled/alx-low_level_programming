//#include <stdio.h>

/**
* main -  print  all possible different combinations of two two-digit numbers
* Return: Always 0 (Success)
*/

int main(void)
{
int i1, i2, j1, j2;
bool f2;
for (i1 = 0; i1 < 10; i1++)
{
	for (i2 = 0; i2 < 10; i2++)
	{
		if (i2 == 9)
		{
			j2 = 0;
			j1 = i1 + 1;
		}
		else
		{
			j2 = i2 + 1;
			j1 = i1;
		}
		f2 = true;
		for (; j1 < 10; j1++)
		{
			if (!f2)
			{
				j2 = 0;
			}
			f2 = false;
			while (j2 < 10)
			{
				// putchar('0' + i1);
				// putchar('0' + i2);
				// putchar(' ');
				// putchar('0' + j1);
				// putchar('0' + j2);
				if (i1 == 9 && i2 == 8 && j1 == 9 && j2 == 9)
				{
					//putchar('\n');
					break;
				}
				else
				{
					// putchar(',');
					// putchar(' ');
				}
				j2++;
			}

		}
	}
}
return (0);
}
