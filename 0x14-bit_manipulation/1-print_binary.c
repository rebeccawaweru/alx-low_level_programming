#include "main.h"

/**
 * print_binary-function that prints binary of a number
 * @n: this is the number to be printed
 */

void print_binary(unsigned long int n)
{
	int y, z;
	unsigned long int a;

	y = 0;
	for (z = 63; z >= 0; z--)
	{
		a = (n >> z) & 1;
		if (a == 1)
			y = 1;
		if (y == 1)
			_putchar(((n >> z) & 1) + '0');
	}
	if (n == 0)
		_putchar('0');
}
