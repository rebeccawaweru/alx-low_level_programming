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
	/* << bitwise operator to shifts bits of a number by index*/
	x = x << index;
	/* ~ flip each bit from 0 to 1 */
	x = ~x;
	*n = *n & x;
	return (1);
}
