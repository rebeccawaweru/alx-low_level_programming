#include "lists.h"

/**
 * insert_dnodeint_at_index - inseart new node at given position
 * @h: head
 * @idx: index
 * @n: integer
 * Return: if not possible/failed NULL else address of new node
 */
dlistint_t *insert_dnodeint_at_index(dlistint_t **h, unsigned int idx, int n)
{
	dlistint_t *current = *h, *node_new;

	if (idx == 0)
		return (add_dnodeint(h, n));
	for (; idx != 1; idx--)
	{
		current = current->next;
		if (current == NULL)
			return (NULL);
	}
	if (current->next == NULL)
		return (add_dnodeint_end(h, n));
	node_new = malloc(sizeof(dlistint_t));
	if (node_new == NULL)
		return (NULL);
	node_new->n = n;
	node_new->prev = current;
	node_new->next = current->next;
	current->next->prev = node_new;
	current->next = node_new;
	return (node_new);
}
