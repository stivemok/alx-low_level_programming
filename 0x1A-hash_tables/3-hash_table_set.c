#include "hash_tables.h"

/**
 * hash_table_set - adds an element to the hash table.
 * @ht: hash table to add or update the key/value to.
 * @key: key to add. cannot be an empty string.
 * @value: value associated with the key.
 * value must be duplicated and can be an empty string.
 * Return: 1 on success, otherwise 0.
 */

int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
	hash_node_t *hash_node;
	hash_node_t *new_node;
	unsigned long int index;

	if (ht == NULL || key == NULL || key[0] == '\0' || value == NULL)
		return (0);
	index = key_index((const unsigned char *)key, ht->size);
	new_node = ht->array[index];
	while (new_node != NULL)
	{
		if (strcmp(new_node->key, key) == 0)
		{
			free(new_node->value);
			new_node->value = strdup(value);
			return (1);
		}
		new_node = new_node->next;
	}
	hash_node = malloc(sizeof(hash_node_t));
	if (hash_node == NULL)
		return (0);
	hash_node->key = strdup(key);
	hash_node->value = strdup(value);
	if (ht->array[index] != NULL)
	{
		hash_node->next = ht->array[index];
	}
	else
		hash_node->next = NULL;
	ht->array[index] = hash_node;
	return (1);
}
