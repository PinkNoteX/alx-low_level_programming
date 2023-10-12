#include "lists.h"
/**
 * delete_dnodeint_at_index - deletes a node at a given index
 * @head: pointer to head
 * @index: index to delete at
 * Return: 1 or -1
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
	unsigned int c = 0;
	dlistint_t *temp;

	if (*head == NULL)
		return (-1);
	temp = *head;
	if (index == 0)
	{
		*head = temp->next;
		if (temp->next != NULL)
			temp->next->prev = NULL;
		free(temp);
		return (1);

	}
	c = 0;
	while (temp != NULL && c < index - 1)
	{
		temp = temp->next;
		c++;
	}
	if (temp->next == NULL || temp == NULL)
		return (-1);
	if (temp->next->next != NULL)
	{
		temp->next = temp->next->next;
		free(temp->next->prev);
		temp->next->prev = temp;
		return (1);
	}
	else
	{
		free(temp->next);
		temp->next = NULL;
		return (1);
	}
	return (-1);
}
