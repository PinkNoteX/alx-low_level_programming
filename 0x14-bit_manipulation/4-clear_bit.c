#include <stdlib.h>
#include "main.h"
#include <stdio.h>
/**
 * clear_bit - sets 0 at a given index.
 * @n: pointer to and unsigned long int.
 * @index; the index
 *
 * Return: 1 or -1
 */
int clear_bit(unsigned long int *n, unsigned int index)
{
	if (index >= sizeof(n) * 8)
		return (-1);

	if (*n & 1L << index)
		*n ^= 1L << index;
	return (1);
}
