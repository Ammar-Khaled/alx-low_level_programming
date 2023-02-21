#include "main.h"
/**
 *  jack_bauer - prints every minute of the day of Jack Bauer, starting from 00:00 to 23:59.
 */
void jack_bauer(void)
{
int hh = 0, mm = 0;
char digits[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'}; 
int h1, h0, m1, m0;
while (hh < 24)
{
	while (mm < 60)
	{
		if (hh < 10)
		{
			h0 = 0;
			h1 = hh;
		}
		else
		{
			h0 = hh % 10;
			h1 = hh / 10;
		}
		_putchar(digits[h0]);
		_putchar(digits[h1]);
		_putchar(':');
		if (mm < 10)
		{
			m0 = 0;
			m1 = mm;
		}
		else
		{
			m0 = mm % 10;
			m1 = mm / 10;
		}
		_putchar(digits[m0]);
		_putchar(digits[m1]);
		_putchar('\n');
		mm++;
	}
	hh++;
}
}
