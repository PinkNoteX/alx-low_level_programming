#include <stdlib.h>
#include <time.h>
#include "main.h"
#include <ctype.h>
/**
 * print_alphabet - Prints the alphabet in lowercase.
 *
 * Return: Always 0 (Success)
 */
void print_alphabet(void)
{
	int x;

	x = 'A';

	while (x <= 'Z')
	{
		char small = tolower(x);

		_putchar(small);
		x++;
	}

	_putchar('\n');
}
