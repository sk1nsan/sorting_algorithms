#include "sort.h"
/**
 * selection_sort - sorting using selection algo
 *
 * @array: array to be sorted
 * @size: size of array
 *
 * Return: Nothing
*/

void selection_sort(int *array, size_t size)
{
	size_t i, j, smallest, temp;

	for (i = 0; i < size - 1; i++)
	{
		smallest = i;
		for (j = i + 1; j < size ; j++)
		{
			if (array[j] < array[smallest])
				smallest = j;
		}
		if (smallest != i)
		{
			temp = array[i];
			array[i] = array[smallest];
			array[smallest] = temp;
			print_array(array, size);

		}
	}
}
