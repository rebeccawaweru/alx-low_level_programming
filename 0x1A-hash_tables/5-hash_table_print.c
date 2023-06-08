#include "hash_tables.h"

/**
 * hash_table_print - print values and keys
 * @ht: hash table
 */
void hash_table_print(const hash_table_t *ht)
{
	unsigned long int index;
	hash_node_t *knob;
	int f = 1;

	if (ht == NULL)
		return;

	printf("{");
	index = 0;
	while (index < ht->size)
	{
		knob = ht->array[index];
		while (knob != NULL)
		{
			if (f == 1)
			{
				printf("'%s': '%s'", knob->key, knob->value);
				f = 0;
			} else
				printf(", '%s': '%s'", knob->key, knob->value);
			knob = knob->next;
		}
		index++;
	}
	printf("}\n");
}
