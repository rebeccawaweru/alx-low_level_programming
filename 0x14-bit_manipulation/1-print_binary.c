#include "main.h"

/**
 * print_binary-function that prints binary of a number
 * @n: this is the number to be printed
 */

void print_binary(unsigned long int n)
{
	while (n > 1)
	{
		n = n >> 1;
		print_binary(n);
	}
	_putchar((n & 1) + '0');
}
