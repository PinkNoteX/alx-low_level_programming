#include "lists.h"
/**
 * insert_dnodeint_at_index - insert a new node at a given index
 * @h: head of linkedlist
 * @idx: index given
 * @n: value to insert at node
 * Return: New list or NULL
 */
dlistint_t *insert_dnodeint_at_index(dlistint_t **h, unsigned int idx, int n)
{
	unsigned int c = 0;
	dlistint_t *temp, *newnode;

	newnode = malloc(sizeof(dlistint_t));
	if (newnode == NULL)
		return (NULL);
	if (h == NULL)
		return (NULL);
	newnode->n = n;
	newnode->prev = NULL;
	newnode->next = NULL;

	temp = *h;
	if (idx == 0)
	{
		newnode = add_dnodeint(h, n);
		return (newnode);
	}

	while (temp != NULL)
	{
		if (c == idx - 1 && temp->next == NULL)
		{
			newnode = add_dnodeint_end(h, n);
			return (newnode);
		}
		else if ((idx - 1) == c)
		{
			newnode->prev = temp;
			newnode->next = temp->next;
			temp->next->prev = newnode;
			temp->next = newnode;
			return (newnode);
		}
		c++;
		temp = temp->next;
	}
	free(newnode);
	return (NULL);
}
