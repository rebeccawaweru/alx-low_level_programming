#include "main.h"

/**
 * get_endianness - checks for endianness
 *
 * Return: 0 if big endian, 1 if small endian
 */

int get_endianness(void)
{
	int a = 1;
	/* use & to get address of variable a*/
	char *endianess = (char *)&a;

	return (*endianess);
}
