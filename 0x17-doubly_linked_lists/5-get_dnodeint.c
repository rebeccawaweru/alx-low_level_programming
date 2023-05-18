#include "lists.h"

/**
 * get_dnodeint_at_index - get the nth node of the list
 * @head: start of the node
 * @index: index of the node
 * Return: nth node else NULL
 */
dlistint_t *get_dnodeint_at_index(dlistint_t *head, unsigned int index)
{
	unsigned int j = 0;
	dlistint_t *x;

	if (head == NULL)
		return (NULL);
	x = head;
	while (x)
	{
		if (index == j)
			return (x);
		x = x->next;
		j++;
	}
	return (NULL);
}
