#include "main.h"

/**
 * flip_bits - returns number of bits you need to flip
 * @n: is an interger
 * @m: is an interger
 *
 * Return: number of flips you need to obtain @m from @n
 */

unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	int bits;
	int j;
	unsigned long int y;
	unsigned long int x;

	bits = 0;
	/*use ^ - a bitwise XOR operator */
	/* n ^ m - performs exclusive OR operation */
	x = n ^ m;

	for (j = 63; j >= 0; j--)
	{
		y = x >> j;
		if (y & 1)
			bits++;

	}
	return (bits);
}
