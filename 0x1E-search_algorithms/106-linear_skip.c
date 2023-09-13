#include "search_algos.h"

/**
 * linear_skip - searches for a value in a sorted skip list of integers
 * @list: a pointer to the head of the skip list to search in
 * @value: the value to search for
 *
 * Return: a pointer on the first node where value is located
 */
skiplist_t *linear_skip(skiplist_t *list, int value)
{
	skiplist_t *knob, *jump;

	if (list == NULL)
		return (NULL);

	for (knob = jump = list; jump->next != NULL && jump->n < value;)
	{
		knob = jump;
		if (jump->express != NULL)
		{
			jump = jump->express;
			printf("Value checked at index [%ld] = [%d]\n",
					jump->index, jump->n);
		}
		else
		{
			while (jump->next != NULL)
				jump = jump->next;
		}
	}
	printf("Value found between indexes [%ld] and [%ld]\n",
			knob->index, jump->index);
	for (; knob->index < jump->index && knob->n < value; knob = knob->next)
		printf("Value checked at index [%ld] = [%ld]\n", knob->index, knob->n);
	printf("Value checked at index [%ld] = [%ld]\n", knob->index, knob->n);
	return (knob->n == value ? knob : NULL);
}
