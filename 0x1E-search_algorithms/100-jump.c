#include "search_algos.h"
#include <math.h>

/**
 * min_val - find the lowest between two numbers
 * @x: the first value
 * @y: the second value
 *
 * Return: the smaller value
 */
size_t min_val(size_t x, size_t y)
{
	if (y < x)
		return (y);
	return (x);
}

/**
 * jump_search - searches for a value using Jump search algorithm
 * @array: the sorted array
 * @size: the size of the array
 * @value: the value to search for
 *
 * Return: the first index where value is located
 */
int jump_search(int *array, size_t size, int value)
{
	size_t j, jump, s;

	if (array == NULL || size == 0)
		return (-1);

	s = sqrt(size);
	for (j = jump = 0; jump < size && array[jump] < value;)
	{
		printf("Value checked array[%ld] = [%d]\n", jump, array[jump]);
		j = jump;
		jump += s;
	}
	printf("Value found between indexes [%ld] and [%ld]\n", j, jump);
	jump = jump < size - 1 ? jump : size - 1;
	for (; j < jump && array[j] < value; j++)
		printf("Value checked array[%ld] = [%d]\n", j, array[j]);
	printf("Value checked array[%ld] = [%d]\n", j, array[j]);
	return (array[j] == value ? (int)j : -1);
}
