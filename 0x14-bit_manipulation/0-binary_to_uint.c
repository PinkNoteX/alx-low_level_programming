#include "main.h"
#include "stdio.h"
#include "string.h"
/**
 * binary_to_uint - converts a binary number to an unsigned int.
 * @b: binary.
 *
 * Return: unsigned int.
 */

unsigned int binary_to_uint(const char *b)
{
	int stringlen = strlen(b);
	int val = 1;
	int total = 0;

	for (int i = (stringlen - 1); i >= 0; i--)
	{
		if (b[i] == '1' || b[i] == '0')
		{
			if (b[i] == '1')
			{
				total += val;
			}
			val *= 2;
		}
		else
		{
			i = 0;
			total = 0;
		}
		return (total);
	}
}
