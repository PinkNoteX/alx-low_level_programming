#include "hash_tables.h"
/**
 *  shash_table_create - create hash table
 *  @size: size of hash table
 *  Return: pointer to hash table or NULL
 */
shash_table_t *shash_table_create(unsigned long int size)
{
	shash_table_t *created = NULL;

	created = malloc(sizeof(shash_table_t));

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
/**
 * shash_table_set - set key/value
 * @ht: hash table
 * @key: the key
 * @value: the value
 * Return: pointer to new hash table
 */
int shash_table_set(shash_table_t *ht, const char *key, const char *value)
{
	unsigned long int x = 0;
	shash_node_t *nhash = NULL;

	if (ht == NULL)
		return (0);
	if (key == NULL || strlen(key) == 0 || value == NULL)
		return (0);
	x = hash_djb2((const unsigned char *)key) % ht->size;
	nhash = malloc(sizeof(shash_node_t));
	if (nhash == NULL)
		return (0);
	nhash->key = strdup(key);
	if (nhash->key == NULL)
	{
		free(nhash);
		return (0);
	}
	nhash->value = strdup(value);
	if (nhash->value == NULL)
	{
		free(nhash->key);
		free(nhash);
		return (0);
	}
	nhash->next = ht->array[x];
	ht->array[x] = nhash;
	return (1);
}
/**
 * shash_table_get - get value
 * @ht: hash table
 * @key: the key
 * Return: pointer to value
 */
char *shash_table_get(const shash_table_t *ht, const char *key)
{
	unsigned long int x = 0;
	shash_node_t *head;

	if (ht == NULL)
		return (NULL);
	if (key == NULL)
		return (NULL);
	x = hash_djb2((unsigned char *)key) % ht->size;
	if (ht->array[x] != NULL)
	{
		head = ht->array[x];

		while (head != NULL)
		{
			if (strcmp(head->key, key) == 0)
				break;
			head = head->next;
		}
	}
	else
		return (NULL);
	return (head->value);
}
/**
 * shash_table_print - print hash table
 * @ht: hash table
 * Return: void
 */
void shash_table_print(const shash_table_t *ht)
{
	unsigned long int x = 0;
	unsigned long int r = 0;
	shash_node_t *head = NULL;

	if (ht == NULL)
		return;
	printf("{");

	while (ht->size > x)
	{
		head = ht->array[x];
		while (head != NULL)
		{
			if (r == 1)
				printf(", ");
			printf("'%s': '%s'", head->key, head->value);
			r = 1;
			head = head->next;
		}
		x++;
	}
	printf("}\n");
}
/**
 * shash_table_print_rev - print hash table
 * @ht: hash table
 * Return: void
 */
void shash_table_print_rev(const shash_table_t *ht)
{
	shash_node_t *head;
	char *s;

	if (ht == NULL)
		return;
	printf("{");
	s = "";

	head = ht->stail;
	while (head != NULL)
	{

		printf("%s'%s': '%s'", s, head->key, head->value);
		s = ", ";
		head = head->sprev;
	}
	printf("}\n");
}
/**
 * shash_table_delete - delete hash table
 * @ht: hash table
 * Return: void
 */
void shash_table_delete(shash_table_t *ht)
{
	shash_node_t *temp, *temp2;

	if (ht == NULL)
		return;
	temp2 = ht->shead;
	while (temp2 != NULL)
	{
		temp = temp2->next;
		free(temp2);
		temp2 = temp;
	}
	free(ht);
}
