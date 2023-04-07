#include "hash_tables.h"

/**
 * shash_table_create - creates a hash table.
 * @size: size of the array.
 * Return: pointer to newly created hash table.
 */
shash_table_t *shash_table_create(unsigned long int size)
{
	shash_table_t *new_table;

	new_table = malloc(sizeof(shash_table_t));
	if (!new_table)
		return (NULL);
	new_table->size = size;
	new_table->array = malloc(sizeof(shash_node_t *) * size);
	if (!new_table->array)
	{
		free(new_table);
		return (NULL);
	}

	return (new_table);
}

/**
 * shash_table_set - adds an element to the hash table.
 * @ht: hash table to add or update the key/value to.
 * @key: key to add. cannot be an empty string.
 * @value: value associated with the key.
 * value must be duplicated and can be an empty string.
 * Return: 1 on success, otherwise 0.
 */

int shash_table_set(shash_table_t *ht, const char *key, const char *value)
{
	shash_node_t *hash_node;
	shash_node_t *new_node;
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
	hash_node = malloc(sizeof(shash_node_t));
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

/**
 * shash_table_get - retrives a value associated with  a key.
 * @ht: hash table to look into.
 * @key: key to look for
 * Return: value associated with the element or NULL if key not found.
 */

char *shash_table_get(const shash_table_t *ht, const char *key)
{
	shash_node_t *node;
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

/**
 * shash_table_print - prints a hash table.
 * @ht: hash table
 * Description: print the key/value in order of apperance
 */

void shash_table_print(const shash_table_t *ht)
{
	shash_node_t *node;
	unsigned long int i = 0;
	int new_node = 0;

	if (ht == NULL)
		return;

	printf("{");
	while (i < ht->size)
	{
		node = ht->array[i];
		while (node != NULL)
		{
			if (new_node == 0)
			{
				printf("'%s': '%s'", node->key, node->value);
				new_node = 1;
			}
			else
				printf(", '%s': '%s'", node->key, node->value);
			node = node->next;
		}
		i++;
	}
	printf("}\n");
}

/**
 * shash_table_print_rev - prints a hash table in reverse.
 * @ht: hash table
 */
void shash_table_print_rev(const shash_table_t *ht)
{
	shash_node_t *node;

	if (ht == NULL)
		return;
	node = ht->stail;
	printf("{");
	while (node != NULL)
	{
		printf("'%s': '%s'", node->key, node->value);
		node = node->sprev;
		if (node != NULL)
			printf(", ");
	}
	printf("}\n");
}

/**
 * shash_table_delete - deletes a hash table.
 * @ht: hash table.
 */
void shash_table_delete(shash_table_t *ht)
{
	shash_node_t *temp;
	unsigned long int i;

	if (ht == NULL)
		return;
	i = 0;
	while (i < ht->size)
	{
		while (ht->array[i] != NULL)
		{
			temp = ht->array[i];
			free(temp->key);
			free(temp->value);
			ht->array[i] = ht->array[i]->next;
			free(temp);
		}
		i++;
	}
	free(ht->array);
	free(ht);
}
