#include <stdlib.h>
#include <time.h>
#include <stdio.h>
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

		putchar(small);
		x++;
	}

	putchar('\n'):
}
