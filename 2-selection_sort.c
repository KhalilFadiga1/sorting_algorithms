#include "sort.h"

/**
 * swap_ints - Swap two integers in an array
 * @a: First num to exchange
 * @b: Second num to exchange
 */
void swap_ints(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * selection_sort - Sort  an array of integers in ascending order using
 * the selection sort algorithm.
 * @array: An integer array
 * @size: Length of array
 * Description: Prints the array after each swap
 */
void selection_sort(int *array, size_t size)
{
	int *min;
	size_t x, y;

	if (array == NULL || size < 2)
		return;
	for (x = 0; x < size - 1; x++)
	{
		min = array + x;
		for (y = x + 1; y < size; y++)
			min = (array[y] < *min) ? (array + y) : min;
		if ((array + x) != min)
		{
			swap_ints(array + x, min);
			print_array(array, size);
		}
	}
}
