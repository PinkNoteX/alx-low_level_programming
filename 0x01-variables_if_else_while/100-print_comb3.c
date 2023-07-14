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
		if (x != n && x != 57)
		{
		putchar(x);
		putchar(n);
		if (n < 58 && x < 57)
		{
		if (n == 57 && x == 56)
		{
		}
		else
		{
			putchar(44);
			putchar(32);
		}
		}
		}
		n++;
	}
		x++;
		n = c + 1;
		c++;
	}
	putchar('\n');
	return (0);
}
