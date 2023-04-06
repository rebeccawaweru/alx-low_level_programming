#include "main.h"

/**
 * clear_bit - sets the value of a bit to 0 at index
 * @n: is an integer
 * @index: is the given index
 * Return: 1 or -1
 */

int clear_bit(unsigned long int *n, unsigned int index)
{
	unsigned long int x;

	while (index >= (sizeof(unsigned long int) * 8))
		return (-1);
	x = 1;
	x = x << index;
	x = ~x;
	*n = *n & x;
	return (1);
}
