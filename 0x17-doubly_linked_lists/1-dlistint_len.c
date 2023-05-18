#include "lists.h"

/**
 * dlistint_len - finds the number of elements in list
 * @h: head
 * Return: number of elements
 */
size_t dlistint_len(const dlistint_t *h)
{
	size_t counter = 0;

	while (h)
	{
		counter++;
		h = h->next;
	}
	return (counter);
}
