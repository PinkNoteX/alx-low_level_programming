#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <ctype.h>
/**
 * main - Entry point
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	int x;
	int z;

	x = 'A';
	z = 'A';

	while (x <= 'Z')
	{
		char small = tolower(x);

		putchar(small);
		x++;
	}
	while (z <= 'Z')
	{
		char small = z;

		putchar(small);
		z++;
	}
	putchar('\n');

	return (0);
}

