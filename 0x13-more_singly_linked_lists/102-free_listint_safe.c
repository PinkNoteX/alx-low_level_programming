#include "lists.h"

/**
 * free_listint_safe - free a `listint_t` list and set the head to null
 * @h: pointer to head
 * Return: size of the list the freed list
 */
size_t free_listint_safe(listint_t **h)
{
	listint_t *list;
	size_t sum;
	int d;

	sum = 0;
	if (!h || !*h)
		return (0);
	while (*h != NULL)
	{
		d = *h - (*h)->next;
		if (d > 0)
		{
			list = (*h)->next;
			free(*h);
			*h = list;
			sum++;
		}
		else
		{
			free(*h);
			*h = NULL;
			sum++
			break;
		}
	}
	*h = NULL;

	return (sum);
}
