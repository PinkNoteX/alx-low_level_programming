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

	srand(time(0));
	n = rand() - RAND_MAX / 2;

	for (int x = 'A'; x <= 'Z'; x++)
	{
		char small = tolower(x);

		putchar(small);
	}

	return (0);
}
