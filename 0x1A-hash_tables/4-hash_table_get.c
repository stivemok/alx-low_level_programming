#include "hash_tables.h"
/**
 * hash_table_get - retrives a value associated with  a key.
 * @ht: hash table to look into.
 * @key: key to look for
 * Return: value associated with the element or NULL if key not found.
 */

char *hash_table_get(const hash_table_t *ht, const char *key)
{
	hash_node_t *node;
	unsigned long int index;

	if (ht == NULL || key == NULL || *key == '\0')
		return (NULL);

	index = key_index((unsigned char *)key, ht->size);
	node = ht->array[index];
	while (node != NULL)
	{
		if (strcmp(node->key, key) == 0)
			return (node->value);
		node = node->next;
	}
	return (NULL);
}
