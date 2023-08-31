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

	if (n > 1)
	{
	print_binary(n >> 1);
	}

	if (n & 1)
	{
		_putchar('1');
	}
	else
	{
		_putchar('0');
	}


}
