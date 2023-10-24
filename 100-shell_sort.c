#include "sort.h"

unsigned int knuth_set(size_t size);
unsigned int knuth_reset(unsigned int previous);
void sorting_back(int **array, int i, int gap);

/**
 * shell_sort - function for sorting an integer array using shell sort
 * @array: The given array to sort
 * @size: size of the array to be sorted
 */

void shell_sort(int *array, size_t size)
{
	int holdr = 0;
	unsigned int gap = 0, i = 0;

	gap = knuth_set(size);
	while (gap)
	{
		for (i = 0; i < size; i++)
		{
			if ((i + gap) < size)
			{
				if (array[i] > array[i + gap])
				{
					holdr = array[i];
					array[i] = array[i + gap];
					array[i +  gap] = holdr;
					sorting_back(&array, (int)i, gap);
				}
			}
		}
		print_array(array, size);
		gap = knuth_reset(gap);
	}
}

/**
 * knuth_set - determines the gap based on knuth sequence
 * @size: size of array to sort
 *
 * Return: returns the largest gap size possible
 */

unsigned int knuth_set(size_t size)
{
	int n = 0, m = 1;
	unsigned int gap = 0;

	if (size == 0)
		return (0);
	if (size == 1)
		return (m);
	while (1)
	{
		gap = (n * 3) + 1;
		if (gap > size)
			return (m);
		m = gap;
		n = gap;
	}
	return (m);
}

/**
 * knuth_reset - determines gap based on knuth sequence
 * @previous: previous gap
 *
 * Return: next gap size possible
 */

unsigned int knuth_reset(unsigned int previous)
{
	unsigned int gap = 0;
	int n = 0, m = 1;

	if (previous == 1)
		return (0);
	while (1)
	{
		gap = (n * 3) + 1;
		if (gap == previous)
			return (m);
		m = gap;
		n = gap;
	}
	return (m);
}

/**
 * sorting_back - sorts the gap back until beginning of array
 * @array: the array to sort
 * @i: the current index
 * @gap: current gap size
 */

void sorting_back(int **array, int i, int gap)
{
	int holdr = 0, j = 0;

	j = i - gap;
	while (j > 0)
	{
		if ((*array)[i] < (*array)[j])
		{
			holdr = (*array)[i];
			(*array)[i] = (*array)[j];
			(*array)[j] = holdr;
		}
		else
			break;
		i -= gap;
		j = i - gap;
	}
}
