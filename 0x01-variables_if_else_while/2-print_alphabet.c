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
	int n;
	int x;

	srand(time(0));
	n = rand() - RAND_MAX / 2;
	x = 'A';

	while (x <= 'Z')
	{
		char small = tolower(x);

		putchar(small);
		x++;
	}

	return (0);
}
