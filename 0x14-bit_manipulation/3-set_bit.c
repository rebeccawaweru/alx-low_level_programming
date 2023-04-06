#include "main.h"

/**
 * set_bit - function that sets value of bit to 1 at index
 * @n: is an integer
 * @index: index given to set 1
 * Return: interger
 */

int set_bit(unsigned long int *n, unsigned int index)
{
	while (index >= (sizeof(*n) * 8))
		return (-1);

	*n ^= (1 << index);
	return (1);
}
