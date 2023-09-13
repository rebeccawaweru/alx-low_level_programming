#include "search_algos.h"

/**
 * recursive_search - search for value using binary search
 * @array: the array
 * @start: the beginning index of the sub array
 * @end: the last index of the subarray
 * @val: the value searched for
 *
 * Return: if val not present, -1 else index where val is located
 */
int recursive_search(int *array, size_t start, size_t end, int val)
{
	size_t j;

	if (end < start)
		return (-1);
	printf("Searching in array: ");
	for (j = start; j < end; j++)
		printf("%d, ", array[j]);
	printf("%d\n", array[j]);

	j = start + (end - start) / 2;
	if (array[j] == val && (j == start || array[j - 1] != val))
		return (j);
	if (array[j] >= val)
		return (recursive_search(array, start, j, val));
	return (recursive_search(array, j + 1, end, val));
}

/**
 * advanced_binary - searches for a value in a sorted array of integers
 * @array: the sorted array
 * @size: the number of elements in array
 * @value: the value to search for
 *
 * Return: index where value is located
 */
int advanced_binary(int *array, size_t size, int value)
{
	if (array == NULL || size == 0)
		return (-1);

	return (recursive_search(array, 0, size - 1, value));
}
