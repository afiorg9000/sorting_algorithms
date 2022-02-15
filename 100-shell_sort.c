#include "sort.h"

/**
 * shell_sort- Shell sort algorithm, using the Knuth sequence
 * @array: array of integers
 * @size: size of array
 * intervals are gaps
 */
void shell_sort(int *array, size_t size)
{
	size_t n = 1, idx, j;
	int tmp;

	if (size < 2 || array == NULL)
	{
		return;
	}
	while (n < size)
	{
		n = n * 3 + 1;
	}
	n /= 3;
	while (n > 0)
	{
		/* finds the max gap*/
		/*decreases gap sequence*/
		/*compares values from begining and from gap*/
		for (idx = n; idx < size; idx ++)
		{
			tmp = array[idx];
			for (j = idx; j >= n && array[j - n] > tmp; j -= n)
				array[j] = array[j - n];
			array[j] = tmp;
		}
		n /= 3;
		print_array(array, size);
	}
}

