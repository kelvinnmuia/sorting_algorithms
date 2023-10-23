#include "sort.h"

/**
 * quick_sort - sorts an array of integers in ascending order using quick sort
 * implements the Lomuto partition scheme to choose pivot
 * @array: array of integers to sort
 * @size: size of array to sort
 */

void quick_sort(int *array, size_t size)
{
	quick_sorting(array, size, array, size);
}

/**
 * quick_sorting - sorts array with quick sort, prints after every switch
 * @array: array or subarray to sort
 * @size: size of array to sort
 * @full_array: full array for printing
 * @full_size: size of full array for printing
 */

void quick_sorting(int *array, size_t size, int *full_array, size_t full_size)
{
	size_t index = 0, pivot = size - 1, placeholder = 0;
	int temp = 0;

	if (size < 2 || array == NULL)
		return;
	for (index = 0; index < pivot; index++)
	{
		if (array[index] < array[pivot] && index == placeholder)
			placeholder++;
		else if (array[index] < array[pivot] && index != placeholder)
		{
			temp = array[index];
			array[index] = array[placeholder];
			array[placeholder] = temp;
			placeholder++;
			print_array(full_array, full_size);
		}
	}
	if (array[pivot] != array[placeholder])
	{
		temp = array[pivot];
		array[pivot] = array[placeholder];
		array[placeholder] = temp;
		print_array(full_array, full_size);
	}

	/* left side */
	quick_sorting(array, placeholder, full_array, full_size);
	/* right side */
	placeholder += 1;
	quick_sorting(&array[placeholder], size - placeholder, full_array, full_size);
}
