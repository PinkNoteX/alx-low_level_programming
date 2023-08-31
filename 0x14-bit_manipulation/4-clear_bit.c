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
	if (index < sizeof(unsigned long int) * 8)
	{
		*n &= (~(1 << index));
		return (1);
	}

	return (-1);
}
