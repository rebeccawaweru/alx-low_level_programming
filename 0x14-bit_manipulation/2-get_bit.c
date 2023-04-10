#include "main.h"

/**
 * get_bit - function returns value of bit in an index
 * @n: is an interger
 * @index: is an index
 * Return: interger
 */

int get_bit(unsigned long int n, unsigned int index)
{
	while (index >= sizeof(unsigned long int) * 8)
		return (-1);
	/* >> right shift operator. Shifts bits to given index*/
	return ((n >> index) & 1);
}
