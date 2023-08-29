#include "lists.h"
/**
 * pop_listint - pops a node out
 * @head: linked list address
 * Return: head node data
 */
int pop_listint(listint_t **head)
{
	listint_t *tmp;
	int val = 0;

	if (*head == NULL)
		return (val);
	tmp = *head;
	val = tmp->n;
	free(*head);
	*head = tmp->next;

	return (val);
}
