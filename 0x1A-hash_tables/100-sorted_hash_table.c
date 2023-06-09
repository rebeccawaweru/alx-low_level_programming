#include "hash_tables.h"

shash_table_t *shash_table_create(unsigned long int size);
int shash_table_set(shash_table_t *ht, const char *key, const char *value);
char *shash_table_get(const shash_table_t *ht, const char *key);
void shash_table_print(const shash_table_t *ht);
void shash_table_print_rev(const shash_table_t *ht);
void shash_table_delete(shash_table_t *ht);

/**
 * shash_table_create - function to create sorted hash table
 * @size: the size of the hashtable
 * Return: pointer else NULL
 */
shash_table_t *shash_table_create(unsigned long int size)
{
	shash_table_t *table;
	unsigned long int j;

	table = malloc(sizeof(shash_table_t));
	if (table == NULL)
		return (NULL);

	table->size = size;
	table->array = malloc(sizeof(shash_node_t *) * size);
	if (table->array == NULL)
		return (NULL);

	for (j = 0; j < size; j++)
		table->array[j] = NULL;
	table->shead = NULL;
	table->stail = NULL;

	return (table);
}

/**
 * shash_table_set - function that adds element to the hash table
 * @ht: sorted hash table
 * @key: the key
 * @value: the value of the key
 * Return: 1 on success else 0
 */
int shash_table_set(shash_table_t *ht, const char *key, const char *value)
{
	shash_node_t *node, *x;
	char *cpy;
	unsigned long int id;

	if (ht == NULL || key == NULL || *key == '\0' || value == NULL)
		return (0);

	cpy = strdup(value);
	if (cpy == NULL)
		return (0);

	id = key_index((const unsigned char *)key, ht->size);
	x = ht->shead;
	while (x)
	{
		if (strcmp(x->key, key) == 0)
		{
			free(x->value);
			x->value = cpy;
			return (1);
		}
		x = x->snext;
	}

	node = malloc(sizeof(shash_node_t));
	if (node == NULL)
	{
		free(cpy);
		return (0);
	}
	node->key = strdup(key);
	if (node->key == NULL)
	{
		free(cpy);
		free(node);
		return (0);
	}
	node->value = cpy;
	node->next = ht->array[id];
	ht->array[id] = node;

	if (ht->shead == NULL)
	{
		node->sprev = NULL;
		node->snext = NULL;
		ht->shead = node;
		ht->stail = node;
	} else if (strcmp(ht->shead->key, key) > 0)
	{
		node->sprev = NULL;
		node->snext = ht->shead;
		ht->shead->sprev = node;
		ht->shead = node;
	} else
	{
		x = ht->shead;
		while (x != NULL && x->snext != NULL && strcmp(x->snext->key, key) < 0)
			x = x->next;
		node->sprev = x;
		if (x != NULL)
			node->snext = x->snext;
		else
			node->snext = NULL;
		if (x != NULL && x->snext == NULL)
			ht->stail = node;
		else if (x->snext != NULL)
			x->snext->sprev = node;
		x->snext = node;
	}
	return (1);
}

/**
 * shash_table_get - get the value
 * @ht: the hash table
 * @key: the key
 * Return: value else NULL
 */
char *shash_table_get(const shash_table_t *ht, const char *key)
{
	shash_node_t *knob;
	unsigned long int idx;

	if (ht == NULL || key == NULL || *key == '\0')
		return (NULL);

	idx = key_index((const unsigned char *)key, ht->size);
	if (idx >= ht->size)
		return (NULL);

	knob = ht->shead;
	while (knob != NULL && strcmp(knob->key, key) != 0)
		knob = knob->snext;

	return ((knob == NULL) ? NULL : knob->value);
}

/**
 * shash_table_print - function to print sorted hash table
 * @ht: the hash table
 */
void shash_table_print(const shash_table_t *ht)
{
	shash_node_t *knob;

	if (ht == NULL)
		return;

	knob = ht->shead;
	printf("{");
	while (knob != NULL)
	{
		printf("'%s': '%s'", knob->key, knob->value);
		knob = knob->snext;
		if (knob != NULL)
			printf(", ");
	}
	printf("}\n");
}

/**
 * shash_table_print_rev - prints sorted hash table in reverse order
 * @ht: the hash table
 */
void shash_table_print_rev(const shash_table_t *ht)
{
	shash_node_t *knob;

	if (ht == NULL)
		return;

	knob = ht->stail;
	printf("{");
	while (knob != NULL)
	{
		printf("'%s': '%s'", knob->key, knob->value);
		knob = knob->sprev;
		if (knob != NULL)
			printf(", ");
	}
	printf("}\n");
}
/**
 * shash_table_delete - function to delte hash_table
 * @ht: hash table
 */
void shash_table_delete(shash_table_t *ht)
{
	shash_table_t *h = ht;
	shash_node_t *knob, *x;

	if (ht == NULL)
		return;

	knob = ht->shead;
	while (knob)
	{
		x = knob->snext;
		free(knob->key);
		free(knob->value);
		free(knob);
		knob = x;
	}
	free(h->array);
	free(h);
}
