#include "search_algos.h"
#include <stdio.h>
/**
 * linear_search - do a linear search on array
 * @array: array to search
 * @size: the size of array
 * @value: value to search
 * Return: index or -1
 */
int linear_search(int *array, size_t size, int value)
{
	unsigned int i;

	for (i = 0; array && i < size; i++)
	{
		printf("Value checked array[%d] = [%d]\n", i, array[i]);
		if (array[i] == value)
			return (i);
	}
	return (-1);
}
