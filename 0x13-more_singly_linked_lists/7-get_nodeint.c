#include "list.h"
/**
 * get_nodeint_at_index - gets node at index
 * @head: linked list at head
 * @index: index node to grab
 * Return: node at index
 */
listint_t *get_nodeint_at_index(listint_t *head, unsigned int index)
{
	unsigned int sum = 0;
	listint_t *tmp;

	tmp = head;
	while (sum != index && tmp != NULL)
	{
		sum++;
		tmp = tmp->next;
	}

	if (sum != index)
		return (NULL);
	return (tmp);
}
