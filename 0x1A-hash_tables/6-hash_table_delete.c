#include "hash_tables.h"
/**
 * hash_table_delete - deletes a hash table.
 * @ht: hash table.
 */
void hash_table_delete(hash_table_t *ht)
{
	hash_node_t *temp;
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
