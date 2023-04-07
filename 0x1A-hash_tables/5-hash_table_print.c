#include "hash_tables.h"

/**
 * hash_table_print - prints a hash table.
 * @ht: hash table
 * Description: print the key/value in order of apperance
 */

void hash_table_print(const hash_table_t *ht)
{
	hash_node_t *node;
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
