#include "sort.h"

/**
 * swap_items - Swaps two items in an array.
 * @array: The array to modify.
 * @item1: The index of the left item.
 * @item2: The index of the right item.
 */
void swap_items(int *array, size_t item1, size_t item2)
{
	int tmp;

	if (array != NULL)
	{
		tmp = array[item1];
		array[item1] = array[item2];
		array[item2] = tmp;
	}
}

/**
 * lomuto_partition - Order a subset of an array of integers according to
 *                    the lomuto partition scheme (last element as pivot).
 * @array: The array of integers.
 * @size: The size of the array.
 * @first: The starting index of the subset to order.
 * @last: The ending index of the subset to order.
 *
 * Return: The final partition index.
 */
int lomuto_partition(int *array, size_t size, int first, int last)
{
	int *pivot, above, below;

	pivot = array + last;
	for (above = below = first; below < last; below++)
	{
		if (array[below] < *pivot)
		{
			if (above < below)
			{
				swap_ints(array + below, array + above);
				print_array(array, size);
			}
			above++;
		}
	}

	if (array[above] > *pivot)
	{
		swap_ints(array + above, pivot);
		print_array(array, size);
	}

	return (above);
}

/**
 * lomuto_sort - Implement the quicksort algorithm through recursion.
 * @array: An array of integers to sort.
 * @size: The size of the array.
 * @first: The starting index of the array partition to order.
 * @last: The ending index of the array partition to order.
 *
 * Description: Uses the Lomuto partition scheme.
 */
void lomuto_sort(int *array, size_t size, int first, int last)
{
	int part;

	if (last - first > 0)
	{
		part = lomuto_partition(array, size, first, last);
		lomuto_sort(array, size, first, part - 1);
		lomuto_sort(array, size, part + 1, last);
	}
}

/**
 * quick_sort - Sort an array of integers in ascending
 *              order using the quicksort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: Uses the Lomuto partition scheme. Prints
 *              the array after each swap of two elements.
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	lomuto_sort(array, size, 0, size - 1);
}
