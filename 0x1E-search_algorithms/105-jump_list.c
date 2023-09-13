#include "search_algos.h"
#include <math.h>

/**
 * next_index - take list forward until index matches last node
 * @list: the list
 * @i: the required index
 *
 * Return: node with required index
 */
listint_t *next_index(listint_t *list, size_t i)
{
	while (list->next != NULL && list->index < i)
		list = list->next;
	return (list);
}

/**
 * jump_list - search for value in sorted list using Jump search algorithm
 * @list: pointer to the head of the list to search in
 * @size: the number of nodes in list
 * @value: the value to search for
 *
 * Return: a pointer to the first node where value is located
 */
listint_t *jump_list(listint_t *list, size_t size, int value)
{
	size_t j;
	listint_t *r, *l;

	if (list != NULL && size > 0)
	{
		j = sqrt(size);
		l = list;
		r = next_index(l, j);
		printf("Value checked at index [%lu] = [%d]\n", r->index, r->n);
		while (r->index < (size - 1) && r->n < value)
		{
			l = r;
			r = next_index(l, r->index + j);
			printf("Value checked at index [%lu] = [%d]\n", r->index, r->n);
		}
		printf("Value found between indexes [%lu] and [%lu]\n",
				l->index, r->index);
		printf("Value checked at index [%lu] = [%d]\n", l->index, l->n);
		while (l->index < size - 1 && l->n < value)
		{
			l = l->next;
			if (l == NULL)
				return (NULL);
			printf("Value checked at index [%lu] = [%d]\n", l->index, l->n);
		}
		if (l->n == value)
			return (l);
	}
	return (NULL);
}
