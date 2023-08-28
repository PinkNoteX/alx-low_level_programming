#include "lists.h"
/*
* print_listint - prints integars in a list
* @h: struct listint_t type
* Return: size_t value or the sum
*/
size_t print_listint(const listint_t *h)
{
	size_t sum = 0;

	while (h != NULL)
	{
		printf("%d\n", h->n);
		sum++;
		h = h->next;
	}

	return (sum);
}
