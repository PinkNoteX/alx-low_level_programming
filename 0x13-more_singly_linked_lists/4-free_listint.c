#include "lists.h"
/**
 * free_listint - frees the list
 * @head: head of struct
 *
 */
void free_listint(listint_t *head)
{
	listint_t *mn;


	while (head != NULL)
	{
		mn = head;
		free(head);
		head = mn->next;
	}

}
