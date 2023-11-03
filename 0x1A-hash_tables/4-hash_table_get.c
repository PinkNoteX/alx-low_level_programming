#include "hash_tables.h"
/**
 * hash_table_get - get a value associated with a key
 * @ht: the hash table
 * @key: the key
 * Return: value or NULL
 */
char *hash_table_get(const hash_table_t *ht, const char *key)
{
	unsigned long int ind = 0;
	hash_node_t *head = NULL;

	if (ht == NULL || key == NULL)
		return (NULL);

	ind = hash_djb2((unsigned char *)key) % ht->size;
	if (ht->array[ind] != NULL)
	{
		head = ht->array[ind];

		while (head != NULL)
		{
			if (strcmp(head->key, key) == 0)
				break;
			head = head->next;
		}

	}
	else
	{
		return (NULL);
	}
	return (head->value);

}
