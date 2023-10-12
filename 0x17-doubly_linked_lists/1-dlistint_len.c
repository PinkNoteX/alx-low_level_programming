#include "lists.h"
/**
 * dlistint_len - returns the number of elements in dlinked list
 * @h: head of dlistint_t
 * Return: Number of elements in linked list
 */
size_t dlistint_len(const dlistint_t *h)
{
	dlistint_t *a;
	unsigned int c = 0;

	a = malloc(sizeof(dlistint_t));
	a = h;

	if (!a)
		return (0);
	while (a)
	{
		a = a->next;
		c++;
	}
	return (c);
}
