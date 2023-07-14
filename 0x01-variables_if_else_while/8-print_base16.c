#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
 * main - Entry point
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	int n = 0;

	while (n < 16)
	{
		printf("%d", n);
		n++;
	}
	putchar('\n');
	return (0);
}
