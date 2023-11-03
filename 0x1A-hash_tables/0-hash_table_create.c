#include "hash_tables.h"

/**
 *  hash_table_create - create hash table
 *  @size: size of hash table
 *  Return: pointer to hash table or NULL
 */
hash_table_t *hash_table_create(unsigned long int size)
{
	hash_table_t *created = NULL;

	created = malloc(sizeof(hash_table_t));

	if (created == NULL)
		return (NULL);
	created->size = size;
	created->array = malloc(sizeof(void *) * size);
	if (created->array == NULL)
	{
		free(created);
		return (NULL);
	}
	return (created);
}
