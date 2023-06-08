#include "hash_tables.h"

/**
 * hash_table_get - Retrieve value associated with a key
 * @ht: pointer
 * @key: the key
 * Return: value else NULL
 */
char *hash_table_get(const hash_table_t *ht, const char *key)
{
	hash_node_t *knob;
	unsigned long int index;

	if (ht == NULL || key == NULL || *key == '\0')
		return (NULL);

	index = key_index((const unsigned char *)key, ht->size);
	if (index >= ht->size)
		return (NULL);

	knob = ht->array[index];
	while (knob && strcmp(knob->key, key) != 0)
		knob = knob->next;

	return ((knob == NULL) ? NULL : knob->value);
}
