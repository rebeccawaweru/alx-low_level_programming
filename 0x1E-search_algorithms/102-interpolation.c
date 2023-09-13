#include "search_algos.h"

/**
 * interpolation_search - search using interpolation search algorithm
 * @array: the sorted array
 * @size: the number of elements in array
 * @value: the value to search for
 *
 * Return: first index where value value is located
 */
int interpolation_search(int *array, size_t size, int value)
{
	size_t h = size - 1, p = 0, lw = 0;
	double t;

	if (!array)
		return (-1);
	while (array[h] != array[lw])
	{
		t = (double)(h - lw) / (array[h] - array[lw]);
		p = lw + (t * (value - array[lw]));
		if (p >= size)
		{
			printf("Value checked array[%d] is out of range\n", (int)p);
			break;
		}
		printf("Value checked array[%d] = [%d]\n", (int)p, array[p]);
		if (array[p] == value)
			return (p);
		else if (array[p] < value)
			lw = p + 1;
		else
			h = p - 1;
	}
	return (value == array[lw] ? (int)lw : -1);
}
