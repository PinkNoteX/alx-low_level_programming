#include "lists.h"

/**
 * free_listint_safe - free a `listint_t` list and set the head to null
 * @h: pointer to head
 * Return: size of the list the freed list
 */
size_t free_listint_safe(listint_t **h)
{
	listint_t *current, *hold;
	size_t sum;

	sum = 0;
	current = *h;
	while (current != NULL)
	{
		sum++;
		hold = current;
		current = current->next;
		free(hold);

		if (hold < current)
			break;
	}
	*h = NULL;

	return (sum);
}
