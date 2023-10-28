#include "sort.h"

void heap_sort(int *array, size_t size);
void max_heapify(int *array, size_t size, size_t base, size_t root);
void swap_ints(int *a, int *b);

/**
 * swap_ints - Swap two integers in the given array.
 * @a: The first integer to swap
 * @b: The second integer to swap
 */
void swap_ints(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * max_heapify - Function to turn a binary tree into a complete binary heap
 * @array: The array of integers representing the binary tree
 * @size: The size of the array
 * @base: The index of the base row of the tree
 * @root: The root node of the binary tree
 */

void max_heapify(int *array, size_t size, size_t base, size_t root)
{
	size_t large, left, right;

	left = 2 * root + 1;
	right = 2 * root + 2;
	large = root;

	if (left < base && array[left] > array[large])
		large = left;

	if (right < base && array[right] > array[large])
		large = right;

	if (large != root)
	{
		swap_ints(array + root, array + large);
		print_array(array, size);
		max_heapify(array, size, base, large);
	}
}

/**
 * heap_sort - function that sorts and integer array
 * in ascending using heap sort
 * @array: the integer array
 * @size: the size of the array
 */
void heap_sort(int *array, size_t size)
{
	int i;

	if (array == NULL || size < 2)
		return;

	for (i = (size / 2) - 1; i >= 0; i--)
		max_heapify(array, size, size, i);

	for (i = size - 1; i > 0; i--)
	{
		swap_ints(array, array + i);
		print_array(array, size);
		max_heapify(array, size, i, 0);
	}
}
