#include "main.h"

/**
 * binary_to_uint- converts binary number to an unsigned int
 *
 *@b:string that contains the binary
 *
 * Return:the converted number
 *
 */

unsigned int binary_to_uint(const char *b)
{
	int j;
	unsigned int number = 0;

	if (b == NULL)
		return (0);
	for (j = 0; b[j] != '\0'; j++)
	{
		if (b[j] == '0')
		{
			number <<= 1;
		} else if (b[j] == '1')
		{
			number = (number << 1) | 1;
		} else
		{
			return (0);
		}
	}
	return (number);
}
