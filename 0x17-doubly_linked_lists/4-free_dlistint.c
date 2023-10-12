#include "lists.h"
/**
 * free_dlistint - frees a doubly linked list
 * @head: head of the list to be freed
 * Return: void
 */
void free_dlistint(dlistint_t *head)
{
	dlistint_t *temp = NULL;

	while (head)
	{
		temp = head;
		head = head->next;
		free(temp);
	}

}
