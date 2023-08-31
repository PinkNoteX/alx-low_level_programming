#include "main.h"

/**
 * flip_bits - returns the number of bits you would
 * need to flip to get from one number to another
 * @n: long int
 * @m: unsigned int
 *
 * Return: 1 or -1
 */
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	unsigned long int nn = 0, ind;

	ind = n ^ m;

	while (ind > 0)
	{
		if (ind & 1)
		{
			nn++;
		}
		ind >>= 1;
	}
	return (nn);
}
