#include "search_algos.h"

/**
 * arry_print - print the elements in an array
 * @array: the array to print
 * @left: the left index of the array
 * @right: the right index of the array
 */

void arry_print(int *array, size_t left, size_t right)
{
	size_t j;

	if (array)
	{
		printf("Searching in array: ");
		for (j = left; j < left + (right - left + 1); j++)
			printf("%d%s", *(array + j), j < left + (right - left) ? ", " : "\n");
	}
}

/**
 * index_search - uses binary search to search for vallue in a sorted array
 * @array: the array
 * @left: the left index
 * @right: the right index
 * @value: the value to look for
 * Return: the first index else -1
 */
int index_search(int *array, size_t left, size_t right, int value)
{
	size_t y;

	if (array == NULL)
		return (-1);
	arry_print(array, left, right);
	y = left + ((right - left) / 2);
	if (left == right)
		return (*(array + y) == value ? (int)y : -1);
	if (value < *(array + y))
		return (index_search(array, left, y - 1, value));
	else if (value == *(array + y))
		return ((int)y);
	else
		return (index_search(array, y + 1, right, value));
}

/**
 * binary_search - using Binary Search algorithm
 * @array: the sorted array
 * @size: the number of elements in the array
 * @value: the value to search for
 *
 * Return: -1 if value is not found or if array is NULL
 */

int binary_search(int *array, size_t size, int value)
{
	return (index_search(array, 0, size - 1, value));
}
