#ifndef _LISTS_
#define _LISTS_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/**
 * struct listnt_s - singly linked list
 * @intnum : an integar
 * @next : points to the next node
 *
 * Description: singly linked list node structure
 */
typedef struct listint_s
{
	int intnum;
	struct listint_s  *next;
} listnt_t;
size_t print_listint(const listint_t *h);
#endif
