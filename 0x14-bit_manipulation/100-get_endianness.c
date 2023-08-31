#include "main.h"
/**
 * get_endianness - Check endianess
 * 
 * Return: 1 or 0
 */
int get_endianness(void)
{
	unsigned int x;
	char *z;

	x = 1;
	z = (char *) &x;

	return ((int)*z);
}
