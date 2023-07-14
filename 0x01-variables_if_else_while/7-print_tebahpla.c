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

	x = 'Z';

	while (x <= 'Z')
	{
		char small = tolower(x);

		putchar(small);
		x = x - 1;
	}
	putchar('\n');

	return (0);
}
