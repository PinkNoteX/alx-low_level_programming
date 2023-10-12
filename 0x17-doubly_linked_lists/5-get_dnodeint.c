#include "lists.h"
/**
 * get_dnodeint_at_index - returns a node at a given index
 * @head: head of the linked list
 * @index: index to stop at
 * Return: a node at a given index or NULL
 */
dlistint_t *get_dnodeint_at_index(dlistint_t *head, unsigned int index)
{
	dlistint_t *temp;
	unsigned int c = 0;

	if (head == NULL)
		return (NULL);
	temp = head;
	while (temp != NULL)
	{
		if (c == index)
			return (temp);
		temp = temp->next;
		c++;
	}
	return (NULL);

}
