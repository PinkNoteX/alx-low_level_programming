#include "main.h"
/**
 * get_endianness - Check endianess
 * Return: void
 */
int get_endianness(void)
{
	unsigned long int n = 1;

	return (*(char *) &n);
}
