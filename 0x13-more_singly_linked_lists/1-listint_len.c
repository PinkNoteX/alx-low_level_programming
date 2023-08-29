#include "lists.h"
/**
* listint_len - returns the sum of elements in a linked list
* @h: struct
* Return: sum of elements
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
