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

	x = 'A';

	while (x <= 'Z')
	{
		char small = tolower(x);

		putchar(small);
		x++;
	}
	putchar('\n';)

	return (0);
}
