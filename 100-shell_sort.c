#include "sort.h"

unsigned int knuth_set(size_t size);
unsigned int knuth_reset(unsigned int previous);
void sorting_back(int **array, int i, int gap);

/**
 * shell_sort - sorts an array of integers using shell sort
 * array is sorted in ascending order
 * shell sort gap is determined by Knuth sequence
 * @array: given array to sort
 * @size: size of array to sort
 *
 */

void shell_sort(int *array, size_t size)
{
/* shell sort: */
/* checks two values separated by gap, swapping if needed */
/* swapping occurs at next gap size until gap size impossible or found spot */

	unsigned int i = 0, gap = 0;
	int holder = 0;

	gap = knuth_set(size);
	while (gap)
	{
		for (i = 0; i < size; i++)
		{
			if ((i + gap) < size)
			{
				if (array[i] > array[i + gap])
				{
					holder = array[i];
					array[i] = array[i + gap];
					array[i + gap] = holder;
					sorting_back(&array, (int)i, gap);
				}
			}
		}
		print_array(array, size);
		gap = knuth_reset(gap);
	}
}

/**
 * knuth_set- determines gap based on Knuth sequence
 * @size: size of array to sort
 *
 * Return: largest gap size possible
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
 * knuth_reset- determines gap based on Knuth sequence
 * @previous: previous gap
 *
 * Return: next gap size possible
 */

unsigned int knuth_reset(unsigned int previous)
{
	int n = 0, m = 1;
	unsigned int gap = 0;

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
 * sorting_back - sorts by gap back until beginning of array
 * @array: array to sort
 * @i: current index
 * @gap: current gap size
 *
 */

void sorting_back(int **array, int i, int gap)
{
	int j = 0, holder = 0;

	j = i - gap;
	while (j > 0)
	{
		if ((*array)[i] < (*array)[j])
		{
			holder = (*array)[i];
			(*array)[i] = (*array)[j];
			(*array)[j] = holder;
		}
		else
			break;
		i -= gap;
		j = i - gap;
	}
}
