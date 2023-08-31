#include "main.h"
/**
 * set_bit - sets the value of a bit to 1. at a given index.
 * @n: pointer of long int.
 * @index: index
 *
 * Return: 1 or -1
 */
int set_bit(unsigned long int *n, unsigned int index)
{
	if (index < sizeof(n) * 8)
	{
		*n = *n | (1 << index);
		return (1);
	}

	return (-1);
}
