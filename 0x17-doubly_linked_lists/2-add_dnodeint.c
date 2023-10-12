#include "lists.h"
/**
 * add_dnodeint - add new node at beginning of linked list
 * @head: pointer to head
 * @n: value to add to new node
 * Return: New linked list with new element or NULL
 */
dlistint_t *add_dnodeint(dlistint_t **head, const int n)
{
	dlistint_t *current, *newnode;

	newnode = malloc(sizeof(dlistint_t));
		if (newnode == NULL)
			return (NULL);
	newnode->n = n;
	newnode->next = NULL;
	newnode->prev = NULL;
	while (*head == NULL)
	{
		newnode->next = NULL;
		*head = newnode;
		return (*head);
	}
	current = *head;
	newnode->next = current;
	current->prev = newnode;
	*head = newnode;
	return (newnode);

}
