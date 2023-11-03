#include "hash_tables.h"
/**
 * key_index - gives an index of a key
 * @key: the key
 * @size: size of hash table
 * Return: index where key/value should be stored
 */
unsigned long int key_index(const unsigned char *key, unsigned long int size)
{
	unsigned long int keyindex = hash_djb2(key) % size;

	return (keyindex);
}
