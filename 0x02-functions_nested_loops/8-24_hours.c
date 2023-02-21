#include "main.h"
/**
 *  jack_bauer - prints every minute of the day of Jack Bauer, starting from 00:00 to 23:59.
 */
void jack_bauer(void)
{
int hh = 0, mm = 0;
int h1, h0, m1, m0;
for (hh = 0; hh < 24; hh++)
{
	for (mm = 0; mm < 60; mm++)
	{
		if (hh < 10)
		{
			h0 = hh;
			h1 = 0;
		}
		else
		{
			h0 = hh % 10;
			h1 = hh / 10;
		}
		_putchar(h1 + '0');
		_putchar(h0 + '0');
		_putchar(':');
		if (mm < 10)
		{
			m0 = mm;
			m1 = 0;
		}
		else
		{
			m0 = mm % 10;
			m1 = mm / 10;
		}
		_putchar(m1 + '0');
		_putchar(m0 + '0');
		_putchar('\n');
		
	}
	
}
}
