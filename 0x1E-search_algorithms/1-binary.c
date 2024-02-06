#include "search_algos.h"
#include <math.h>
#include <stdio.h>
/**
 * printarr - print current array
 * @arr: The array
 * @start: start index to print arr from
 * @end: end index to end print arr at
 * Return: void
*/
void printarr(int *arr, int start , int end)
{
	int i = 0;

	printf("Searching in array: ");
	for (i = start; i <= end; i++)
		if (i != end)
			printf("%d, ", arr[i]);
		else
			printf("%d\n", arr[i]);
}
/**
 * divide - divide the array from target to start or end
 * @arr: The array
 * @target: target value to search for
 * @start: start of arr
 * @end: end of arr
 * Return: index target is at or recursion or -1
*/
int divide(int *arr,int target, int start, int end)
{
	int mid;

	printarr(arr, start, end);
	mid = floor((start + end)/2);
	if (target > arr[end] && mid == end)
		return -1;
	if (target == arr[mid])
		return mid;
	if (target > arr[mid])
		return divide(arr, target, mid+1, end);
	if (target < arr[mid])
		return divide(arr, target, start, mid-1);
	return -1;
}
/**
 * binary_search - binary search algorithm
 * @array: The array
 * @size: array size
 * @value: value to search for
 * Return: the index target is at or -1
*/
int binary_search(int *array, size_t size, int value)
{
	int start = 0;
	int end = size - 1;
	return divide(array, value, start, end);
}
