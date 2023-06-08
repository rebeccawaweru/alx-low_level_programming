#include "hash_tables.h"

/**
 * hash_table_delete - Deletes a hash table
 * @ht: hash table
 */
void hash_table_delete(hash_table_t *ht)
{
	hash_table_t *h = ht;
	unsigned long int j;
	hash_node_t *node, *x;

	for (j = 0; j < ht->size; j++)
	{
		if (ht->array[j] != NULL)
		{
			node = ht->array[j];
			while (node != NULL)
			{
				x = node->next;
				free(node->key);
				free(node->value);
				free(node);
				node = x;
			}
		}
	}
	free(h->array);
	free(h);
}
