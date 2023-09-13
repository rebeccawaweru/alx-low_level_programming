#include "search_algos.h"

/**
 * linear_search - Searches for a value in an array using Linear Search
 * @array: the array of integers
 * @size: the number of elements in the array
 * @value: the value to search for
 * Return: -1 if value not found or if array is NULL else 1
 */

int linear_search(int *array, size_t size, int value)
{
	size_t j;

	for (j = 0; (j < size) && (array); j++)
	{
		if (*(array + j) == value)
		{
			printf("Value checked array[%d] = [%d]\n", (int)j, *(array + j));
			return (j);
		}
		else
		{
			printf("Value checked array[%d] = [%d]\n", (int)j, *(array + j));
		}
	}
	return (-1);
}
