#include "search_algos.h"

/**
 * s_binary - search using binary search
 * @array: the array
 * @start: the first index
 * @last: the last index
 * @val: the value searched
 *
 * Return: -1 or index where value is located
 */
int s_binary(int *array, size_t start, size_t last, int val)
{
	size_t j;

	if (array == NULL)
		return (-1);

	while (last >= start)
	{
		printf("Searching in array: ");
		for (j = start; j < last; j++)
			printf("%d, ", array[j]);
		printf("%d\n", array[j]);

		j = start + (last - start) / 2;
		if (array[j] == val)
			return (j);
		if (array[j] > val)
			last = j - 1;
		else
			start = j + 1;
	}
	return (-1);
}
/**
 * exponential_search - search using Exponential search algorithm
 * @array: the sorted array of integers
 * @size: the number of elements in array
 * @value: the value to search for
 *
 * Return: the first index where value is located
 */
int exponential_search(int *array, size_t size, int value)
{
	size_t j = 0, right;

	if (array == NULL)
		return (-1);

	if (array[0] != value)
	{
		for (j = 1; j < size && array[j] <= value; j = j * 2)
			printf("Value checked array[%ld] = [%d]\n", j, array[j]);
	}
	right = j < size ? j : size - 1;
	printf("Value found between indexes [%ld] and [%ld]\n", j / 2, right);
	return (s_binary(array, j / 2, right, value));
}
