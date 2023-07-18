#include <stdlib.h>
#include <time.h>
#include "main.h"
#include <ctype.h>
/**
 * print_alphabet_x10 - Prints the alphabet in lowercase.
 *
 * Return: Always 0 (Success)
 */
void print_alphabet_x10(void)
{
	int x;
	int y = 10;

	x = 'A';
	while (y != 0)
	{
	while (x <= 'Z')
	{
		char small = tolower(x);

		_putchar(small);
		x++;
	}
	_putchar('\n');
	y--;
	x = 'A';
	}
}
