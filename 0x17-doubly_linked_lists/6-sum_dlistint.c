#include "lists.h"
/**
 * sum_dlistint - returns the sum of linked list values
 * @head: head of the linked list
 * Return: sum or 0
 */
int sum_dlistint(dlistint_t *head)
{
	int num = 0;

	if (head == NULL)
		return (0);
	while (head != NULL)
	{
		num = num + head->n;
		head = head->next;
	}
	return (num);

}
