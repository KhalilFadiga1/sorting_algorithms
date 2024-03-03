#include "sort.h"

/**
 * swap_ints - Exchange two numbers in an array
 * @a: First num
 * @b: Second num
 */
void swap_ints(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * bubble_sort - Sort integer array from smallest to biggest
 * @array: The integer array
 * @size: Length of the array
 * Description: Prints the array after each swap
 */
void bubble_sort(int *array, size_t size)
{
	size_t x, length = size;
	bool bubble = false;

	if (array == NULL || size < 2)
		return;
	while (bubble == false)
	{
		bubble = true;
		for (x = 0; x < length - 1; x++)
		{
			if (array[x] > array[x + 1])
			{
				swap_ints(array + x, array + x + 1);
				print_array(array, size);
				bubble = false;
			}
		}
		length--;
	}
}
