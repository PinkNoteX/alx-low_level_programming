#ifndef SEARCH_ALGOS_H
#define SEARCH_ALGOS_H
#include <stdlib.h>
int linear_search(int *array, size_t size, int value);
int binary_search(int *array, size_t size, int value);
void printarr(int *arr, int start, int end);
int divide(int *arr, int target, int start, int end);
#endif
