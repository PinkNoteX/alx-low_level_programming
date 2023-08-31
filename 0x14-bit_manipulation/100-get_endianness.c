#include "main.h"
/**
 * get_endianness - Check endianess
 * 
 * Return: 1 or 0
 */
int get_endianness(void)
{
	unsigned long int n = 1;
	return (*(char *)&n);
}
