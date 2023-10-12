#include "lists.h"
/**
 * add_dnodeint_end - add new node at the end of the linked list
 * @head: point to head
 * @n: value to add
 * Return: A new linked list or NULL
 */
dlistint_t *add_dnodeint_end(dlistint_t **head, const int n)
{
	dlistint_t *curr, *newnode;

	newnode = malloc(sizeof(dlistint_t));
	if (newnode == NULL)
		return (NULL);
	newnode->n = n;
	newnode->next = NULL;
	newnode->prev = NULL;
	while (*head == NULL)
	{
		*head = newnode;
		return (*head);
	}
	curr = *head;
	while (curr->next != NULL)
	{
		curr = curr->next;
	}
	newnode->prev = curr;
	curr->next = newnode;
	return (newnode);
}
