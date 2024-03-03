#include "sort.h"

void swap_ints(int *a, int *b);
int lomuto_partition(int *array, size_t size, int left, int right);
void lomuto_sort(int *array, size_t size, int left, int right);
void quick_sort(int *array, size_t size);

/**
 * swap_ints - Swap  two elements in an array
 * @a: First int to swap
 * @b: Second int to swap
 */
void swap_ints(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * lomuto_partition - Order a subset of an array of integer according to the
 * lomuto partition scheme(last element as pivot)
 * @array: Array of integers.
 * @size: Length of the array.
 * @left: The beginning index of the subset to order.
 * @right: The ending index of the subset to order.
 * Return: The final partition index.
 */
int lomuto_partition(int *array, size_t size, int left, int right)
{
	int *pivot, abv, bel;

	pivot = array + right;
	for (abv = bel = left; bel < right; bel++)
	{
		if (array[bel] < *pivot)
		{
			if (abv < bel)
			{
				swap_ints(array + bel, array + abv);
				print_array(array, size);
			}
			abv++;
		}
	}
	if (array[abv] > *pivot)
	{
		swap_ints(array + abv, pivot);
		print_array(array, size);
	}
	return (abv);
}

/**
 * lomuto_sort - Implement the quicksort algorithm through recursion.
 * @array: An array of integers to sort.
 * @size: The size of the array.
 * @left: The starting index of the array partition to order.
 * @right: The ending index of the array partition to order.
 * Description: Uses the Lomuto partition scheme.
 */
void lomuto_sort(int *array, size_t size, int left, int right)
{
	int part;

	if (right - left > 0)
	{
		part = lomuto_partition(array, size, left, right);
		lomuto_sort(array, size, left, part - 1);
		lomuto_sort(array, size, part + 1, right);
	}
}

/**
 * quick_sort - Sort an array of integers in ascending
 *              order using the quicksort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 * Description: Uses the Lomuto partition scheme
 * Prints the array after each swap of two elements.
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	lomuto_sort(array, size, 0, size - 1);
}
