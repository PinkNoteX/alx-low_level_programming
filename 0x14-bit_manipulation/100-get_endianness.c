#include "main.h"
/**
 * get_endianness - Check endianess
 * 
 * Return: 1 or 0
 */
int get_endianness(void)
{
	int x;

	x = 2;

	if (x & 1)
	{
		return (0);
	}

	return (1);
}
