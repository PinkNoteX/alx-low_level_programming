#include "lists.h"
/**
 * delete_nodeint_at_index - deletes a node
 * @head: linked list at head
 * @index: index of deleted node
 * Return: bool
 */
int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
	listint_t *tmp, *_delete;
	unsigned int sum = 0;

	tmp = *head;
	if (*head == NULL)
		return (-1);
	if (index == 0)
	{
		tmp = tmp->next;
		free(*head);
		*head = tmp;
		return (1);
	}
	else
	{
		while (tmp != NULL && sum != index - 1)
		{
			sum++;
			tmp = tmp->next;
		}
		if (sum != index - 1)
			return (-1);
		_delete = tmp->next;
		tmp->next = tmp->next->next;
		free(_delete);
		return (1);
	}

}
