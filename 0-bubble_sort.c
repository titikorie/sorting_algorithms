#include "sort.h"

/**
 * bubble_sort - sorts an array of integers in ascending order
 * using the Bubble sort algorithm
 * prints the array after each time you swap two elements
 *
 * @array: The array to be sorted
 * @size: Size of the array
 */

void bubble_sort(int *array, size_t size)
{
	size_t i, counter;
	int temp_swap, flag = 0;

	/*Check inputs*/
	if (array == NULL || size == 0)
	{
		return;
	}

	/* Counts through the current step in the sort */
	for (i = 0; i < size - 1; i++)
	{
		/* Loop through array */
		for (counter = 0; counter < size - i - 1; counter++)
		{
			if (array[counter] > array[counter + 1])
			{
				/* Swap a[i] with a[1 + 1] */
				temp_swap = array[counter];
				array[counter] = array[counter + 1];
				array[counter + 1] = temp_swap;
				/* Print result */
				print_array(array, size);
				flag = 1;
			}
		}
		if (flag == 0)
		{
			break;
		}
	}
}
