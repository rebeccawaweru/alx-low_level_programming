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
	size_t left, right, j;
	int v;

	if (array != NULL && size > 0)
	{
		j = sqrt(size);
		left = 0;
		right = j;
		v = array[left];
		printf("Value checked array[%lu] = [%d]\n", left, v);
		while (right < size && v < value)
		{
			if (array[right] >= value)
				break;
			left += j;
			right += j;
			v = array[left];
			printf("Value checked array[%lu] = [%d]\n", left, v);
		}
		if (left >= size || v > value)
			return (-1);
		printf("Value found between indexes [%lu] and [%lu]\n", left, right);
		while (left <= min_val(size - 1, right) && v <= value)
		{
			v = array[left];
			printf("Value checked array[%lu] = [%d]\n", left, v);
			if (v == value)
				return (1);
			left++;
		}
	}
	return (-1);
}
