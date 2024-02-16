#include "sort.h"
/**
 * partition - helper function2
 *
 * @array: array to be sorted
 * @f: first element of array
 * @l: last element of array
 * @size: size of array
 *
 * Return: pivot index
 */

int partition(int *array, int f, int l, int size)
{
	int pivot = array[l];
	int i = f - 1;
	int j, temp;

	for (j = f; j < l; j++)
	{
		if (array[j] <= pivot)
		{
			i++;
			temp = array[i];
			array[i] = array[j];
			array[j] = temp;
			print_array(array, size);

		}
	}
	i++;
	temp = array[i];
	array[i] = array[l];
	array[l] = temp;
	print_array(array, size);

	return (i);
}
/**
 * quick_sort2 - helper function
 *
 * @array: array to be sorted
 * @f: first element of array
 * @l: last element of array
 * @size: size of array
 *
 * Return: Nothing
 */

void quick_sort2(int *array, int f, int l, int size)
{
	int q;

	if (l > f && f >= 0)
	{
		q = partition(array, f, l, size);
		quick_sort2(array, f, q - 1, size);
		quick_sort2(array, q + 1, l, size);
	}
}
/**
 * quick_sort - sorting using quicksort algo
 *
 * @array: array to be sorted
 * @size: size of array
 *
 * Return: Nothing
 */

void quick_sort(int *array, size_t size)
{
	quick_sort2(array, 0, size - 1, size);
}
