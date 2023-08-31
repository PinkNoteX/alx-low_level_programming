#include <stdio.h>
#include "main.h"

/**
 * print_binary - convert decimal to binary
 * @n: unsigned long int.
 *
 * Return: no return.
 */

void print_binary(unsigned long int n)
{
	int i, counter = 0;
	unsigned long int currnum;

	for (i = 63; i >= 0; i--)
	{
		currnum = n >> i;
		if (currnum & 1)
		{
		_putchar('1');
		counter++;
		}
		else if (counter)
		_putchar('0');
	}
	if (!counter)
		_putchar('0');
}
