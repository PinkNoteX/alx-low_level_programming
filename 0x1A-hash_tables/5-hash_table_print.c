#include "hash_tables.h"
/**
 * hash_table_print - prints the hash table
 * @ht: hash table to print
 * Return: void
 */
void hash_table_print(const hash_table_t *ht)
{
	unsigned long int x;
	char *s;
	hash_node_t *temp;

	if (ht == NULL)
		return;
	printf("{");
	s = "";

	for (x = 0; x < ht->size; x++)
	{
		temp = ht->array[x];
		while (temp != NULL)
		{
			printf("%s'%s': '%s'", s, temp->key, temp->value);
			s = ", ";
			temp = temp->next;
		}
	}
	printf("}\n");
}
