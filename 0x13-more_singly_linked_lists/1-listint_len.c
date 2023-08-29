#include "lists.h"
/**
* listint_len - returns the sum of elemens in a linked list
* @h: struct listint_t type
* Return: the sum
*/
size_t listint_len(const listint_t *h)
{
        size_t sum = 0;

        while (h != NULL)
        {
                sum++;
                h = h->next;
        }

        return (sum);
}
