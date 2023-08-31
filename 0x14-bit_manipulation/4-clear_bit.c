#include "main.h"
/**
 * clear_bit - sets 0 at a given index.
 * @n: pointer to and unsigned long int.
 * @index; the index, starting from 0 of the bit you want to set
 *
 * Returns: 1 if it worked, or -1 if an error occurred
 */
int clear_bit(unsigned long int *n, unsigned int index)
{
	if (index >= sizeof(n) * 8)
		return (-1);

	if (*n & 1L << index)
		*n ^= 1L << index;
	return (1);
}
