#include "lists.h"

/**
 * sum_dlistint - sum of all data in the list
 * @head: start of the node
 * Return: sum of data or if list empty 0
 */
int sum_dlistint(dlistint_t *head)
{
	int total = 0;
	dlistint_t *num;

	if (head == NULL)
		return (total);
	num = head;
	while (num)
	{
		total += num->n;
		num = num->next;
	}
	return (total);
}
