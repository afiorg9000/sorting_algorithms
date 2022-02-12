#include "sort.h"

/**
 * merge_sort - merge_sort algorithm
 * @array: array of int
 * @size: size of array
 */
void merge_sort(int *array, size_t size)
{
	int *tmp = malloc(sizeof(int) * (size));

	if (size < 2 || array == NULL || tmp == NULL)
		return;

	merge_split(array, 0, size - 1, tmp);
	free(tmp);
}

/**
 * merge_split- splits the array into sub-arrays
 * @array: array of integers to be sorted
 * @start: first half of the index to be sorted
 * @end: second half of the index to be sorted
 * @tmp: tmp array
 */
void merge_split(int *array, size_t start, size_t end, int *tmp)
{
	size_t mid = 0;

	if (start < end)
	{
		mid = ((start + end - 1) / 2);
		/* ^ Find the middle point to divide the array into two halves*/
		merge_split(array, start, mid, tmp);
		/*^Call half_split for first half*/
		merge_split(array, mid + 1, end, tmp);
		/*^Call half_split for second half*/
		merge(array, start, mid, end, tmp);
		/*Merge the two halves sorted in step 2 and 3*/
	}
}

/**
 * merge - merges two subarrays
 * @array: array to be sorted
 * @start: first half
 * @mid: middle
 * @end: second half
 * @tmp: tmp array
 */
void merge(int *array, size_t start, size_t mid, size_t end, int *tmp)
{
	size_t i = start, j, k;
	/*initial indexes of first, second and merged array*/
	j = mid = (start + end) / 2;

	printf("Merging...\n");
	printf("[left]: ");
	print_array(array + start, mid - start);

	printf("[right]: ");
	print_array(array + mid, end - mid);

	for (k = start; k < end; k++)
		if (i < mid && (j >= end || array[i] <= array[j]))
		{
			tmp[k] = array[i++];
		}
		else
		{
			tmp[k] = array[j++];
		}
	printf("[Done]: ");
	print_array(tmp + start, end - start);
}
