#include "main.h"
#include "stdio.h"
/**
 * binary_to_uint - converts a binary number to an unsigned int.
 * @b: binary.
 *
 * Return: unsigned int.
 */

unsigned int binary_to_uint(const char *b)
{
	int i;
	int val = 1;
	unsigned int total = 0;

	for (i = 0; b[i] != '\0'; i++)
		;
	for (i--; i >= 0; i--, val *= 2)
	{
		if (b[i] == '1' || b[i] == '0')
		{
			if (b[i] == '1')
			{
				total += val;
			}
		}
		else
		{
			return (0);
		}
	}
	return (total);
}
