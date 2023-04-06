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
	unsigned long int x;

	bits = 0;
	x = n ^ m;
	if (x > 0)
	{
		bits += (x & 1);
		x >>= 1;
	};
	return (bits);
}
