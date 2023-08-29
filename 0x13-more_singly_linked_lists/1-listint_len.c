#include "lists.h"
/**
* listint_len - prints integars in a list
* @h: struct listint_t type
* Return: size_t value or the sum
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
