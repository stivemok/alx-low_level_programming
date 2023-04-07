#include "hash_tables.h"
/**
 * key_index - gives the index of a key.
 * @key:  key to the index.
 * @size: size of the array of the hash table.
 * use the hash_djb2 function
 * Return: the index at which the key/value pair
 * should be stored in the array of the hash table
 */

unsigned long int key_index(const unsigned char *key, unsigned long int size)
{
	return (hash_djb2(key) % size);
}
