#include "lists.h"
#include <stdio.h>

/**
 * looped_listint_len - Counts the number of nodes
 *                      in a looped listint_t linked list.
 * @head: A pointer to the head of the listint_t to check.
 *
 * Return: number of nodes
 */
size_t looped_listint_len(const listint_t *head)
{
	const listint_t *tor, *hare;
	size_t number = 1;

	if (head == NULL || head->next == NULL)
		return (0);

	tor = head->next;
	hare = (head->next)->next;

	while (hare)
	{
		if (tor == hare)
		{
			tor = head;
			while (tor != hare)
			{
				number++;
				tor = tor->next;
				hare = hare->next;
			}

			tor = tor->next;
			while (tor != hare)
			{
				number++;
				tor = tor->next;
			}

			return (number);
		}

		tor = tor->next;
		hare = (hare->next)->next;
	}

	return (0);
}

/**
 * print_listint_safe - Print a `listint_t` linked list including mem addresses
 * @head: head of linked list
 * Description: Go through list once
 * Return: number of nodes in list. If fails, exit with status 98.
 */
size_t print_listint_safe(const listint_t *head)
{
	size_t number, index = 0;

	number = looped_listint_len(head);

	if (number == 0)
	{
		for (; head != NULL; number++)
		{
			printf("[%p] %d\n", (void *)head, head->n);
			head = head->next;
		}
	}

	else
	{
		for (index = 0; index < number; index++)
		{
			printf("[%p] %d\n", (void *)head, head->n);
			head = head->next;
		}

		printf("-> [%p] %d\n", (void *)head, head->n);
	}

	return (number);
}
