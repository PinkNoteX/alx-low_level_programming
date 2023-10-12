#include "lists.h"
/**
 * print_dlistint - print number of elements in doubly linked list
 * @h: head of dlistint_t
 * Return: number of elements
 */
size_t print_dlistint(const dlistint_t *h)
{
	unsigned int c = 0;

	while (h != NULL)
	{
		printf("%d\n", h->n);
		h = h->next;
		c++;
	}
	return (c);

}
