#include "main.h"
/**
 * clear_bit - sets 0 at a given index.
 * @n: pointer to and unsigned long int.
 * @index; the index
 *
 * Return: 1 or -1
 */
int clear_bit(unsigned long int *n, unsigned int index)
{
	unsigned int num;

	if (index > 63)
		return (-1);

	num = 1 << index;

	if (*n & num)
		*n ^= num;

	return (1);
}
