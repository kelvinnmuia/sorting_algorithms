#include "sort.h"

void hoare_sort(int *array, size_t size, int left, int right);
int hoare_partition(int *array, size_t size, int left, int right);
void swap_ints(int *a, int *b);
void quick_sort_hoare(int *array, size_t size);

/**
 * hoare_sort - implementing the quicksort algorithm through recursion
 * @array: The integer array to be sorted
 * @size: The size of the array
 * @left: The starting index of the array partition to order
 * @right: The ending index of the array partition to order
 */
void hoare_sort(int *array, size_t size, int left, int right)
{
	int part;

	if (right - left > 0)
	{
		part = hoare_partition(array, size, left, right);
		hoare_sort(array, size, left, part - 1);
		hoare_sort(array, size, part, right);
	}
}

/**
 * hoare_partition - Order a subset of an integer array
 * based on the hoare partition scheme.
 * @array: The array of integers
 * @size: The size of the array.
 * @left: The starting index of the subset to order.
 * @right: The ending index of the subset to order.
 *
 * Return: The final partition index
 */
int hoare_partition(int *array, size_t size, int left, int right)
{
	int pivot, above, below;

	pivot = array[right];
	for (above = left - 1, below = right + 1; above < below;)
	{
		do {
			above++;
		} while (array[above] < pivot);
		do {
			below--;
		} while (array[below] > pivot);

		if (above < below)
		{
			swap_ints(array + above, array + below);
			print_array(array, size);
		}
	}
	return (above);
}

/**
 * swap_ints - Swaps two integers in an array.
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
 * quick_sort_hoare - function for sorting an integer
 * array in ascending order using the quicksort algorithm.
 * @array: an integer array
 * @size: The size of the array
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	hoare_sort(array, size, 0, size - 1);
}
