#include "hash_tables.h"
/**
 * hash_table_delete - delete hash table
 * @ht: hash table to delete
 * Return: void
 */
void hash_table_delete(hash_table_t *ht)
{
	unsigned long int x;
	hash_node_t *temp, *temp2;

	if (ht == NULL)
		return;

	for (x = 0; x < ht->size; x++)
	{
		temp = ht->array[x];
		while ((temp2 = temp) != NULL)
		{
			temp = temp->next;
			free(temp2->key);
			free(temp2->value);
			free(temp2);
		}
	}
	free(ht->array);
	free(ht);
}
