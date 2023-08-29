#include "lists.h"
/**
 * find_listint_loop - find the loop
 * @head: head
 * Return: Address of node where loop starts, or NULL if no loop found.
 */
listint_t *find_listint_loop(listint_t *head)
{
	listint_t *currs, *fast;

	if (head == NULL)
		return (NULL);

	currs = fast = head;
	do {
		if (currents->next)
			currs = currs->next;
		else
			return (NULL);

		if (currentf->next->next)
			fast = fast->next->next;
		else
			return (NULL);
	} while (fast != currs);

	currs = head;
	while (fast != currs)
	{
		currf = fast->next;
		currs = currs->next;
	}

	return (currs);
}
