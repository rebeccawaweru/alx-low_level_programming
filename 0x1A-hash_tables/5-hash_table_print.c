#include "hash_tables.h"

/**
 * hash_table_print - print values and keys
 * @ht: hash table
 */
void hash_table_print(const hash_table_t *ht)
{
	unsigned long int index = 0;
	hash_node_t *knob;
	char *q = "";

	if (!ht || !ht->array)
		return;

	putchar('{');
	if (index < ht->size)
	{
		knob = ((ht->array)[index]);
		while (knob)
		{
			printf("%s'%s': '%s'", q, knob->key, knob->value);
			q = ", ";
			knob = knob->next;
		}
		index++;
	}
	puts("}");
}
