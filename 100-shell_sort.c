#include "sort.h"

/**
 * shell_sort- Shell sort algorithm, using the Knuth sequence
 * @array: array of integers
 * @size: size of array
 * intervals are gaps
 */
void shell_sort(int *array, size_t size)
{
	size_t gap = sizeof(size), idx;

	if (size < 2 || array == NULL)
	{
		return;
	}

	while (gap < (size / 3))
		gap = gap * 3 + 1;
	/* finds the max gap*/
	{
		for (; gap > 0; gap /= 3)
			/*decreases gap sequence*/
			/*compares values from begining and from gap*/
		{

			for (idx = gap; idx < size; idx++)
			{
				for (; idx >= gap && array[idx - gap] > array[idx]; idx -= gap)
				{
					array[idx] = array[idx - gap];
				}
				array[idx] = array[idx];
			}
			print_array(array, size);
		}
	}
}
