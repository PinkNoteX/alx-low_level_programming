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
	int n = 49;
	int x = 48;
	int c = 49;

	while (x < 58)
	{
		while (n < 58)
	{
		putchar(x);
		putchar(n);
		if (n < 57 && x != 57)
		{
			putchar(44);
			putchar(32);
		}
		n++;
	}
		x++;
		n = c + 1;
	}
	putchar('\n');
	return (0);
}

