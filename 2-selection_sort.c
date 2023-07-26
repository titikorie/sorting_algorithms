#include "sort.h"
#include <stdio.h>


/**
 * selection_sort - sorts an array of integers in ascending order
 * @array: The array
 * @size: The size of the array
 *
 * Return: void
 */
void selection_sort(int *array, size_t size)
{
	size_t i, swap, index;
	int tmp;

	for (swap = 0; swap < size - 1; swap++)
	{
		index = swap;
		for (i = swap + 1; i < size; i++)
		{
			if (array[i] < array[index])
				index = i;
		}

		if (index != swap)
		{
			tmp = array[swap];
			array[swap] = array[index];
			array[index] = tmp;
			print_array(array, size);
		}
	}
}
