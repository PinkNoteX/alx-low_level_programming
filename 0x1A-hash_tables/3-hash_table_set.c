#include "hash_tables.h"
/**
 * hash_table_set - add element to hash table
 * @ht: the hash table
 * @key: the key
 * @value: value to add
 * Return: 1 or 0
 */
int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
	unsigned long int index;

	if (ht == NULL)
		return (0);
	if (key == NULL || *key == '\0')
		return (0);
	index = key_index((unsigned char *)key, ht->size);
	if (hash_add(&(ht->array[index]), key, value) == NULL)
		return (0);
	return (1);
}
/**
 * hash_add - add a node at beginning
 * @head: the head
 * @key: the key
 * @value: the value
 * Return: head of hash
 */
hash_node_t *hash_add(hash_node_t **head, const char *key, const char *value)
{
	hash_node_t *temp;

	temp = *head;
	while (temp != NULL)
	{
		if (strcmp(key, temp->key) == 0)
		{
			free(temp->value);
			temp->value = strdup(value);
			return (*head);
		}
		temp = temp->next;
	}
	temp = malloc(sizeof(hash_node_t));
	if (temp == NULL)
		return (NULL);

	temp->key = strdup(key);
	temp->value = strdup(value);
	temp->next = (*head);
	*head = temp;

	return (*head);

}
