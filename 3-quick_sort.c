#include "sort.h"

static void swap_and_print(int *array, size_t size, int i, int j);
static int lomuto_partition(int *array, size_t size, int low, int high);
static void quick_sort_recursive(int *array, size_t size, int low, int high);

/**
 * quick_sort - Sorts an array of integers in ascending order
 *              using the Quick sort algorithm (Lomuto partition scheme)
 * @array: Pointer to the array to sort
 * @size: Number of elements in the array
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	quick_sort_recursive(array, size, 0, (int)size - 1);
}

/**
 * swap_and_print - Swaps two values in an array and prints it
 * @array: Pointer to the array
 * @size: Number of elements in the array
 * @i: First index
 * @j: Second index
 */
static void swap_and_print(int *array, size_t size, int i, int j)
{
	int tmp;

	if (i == j || array[i] == array[j])
		return;

	tmp = array[i];
	array[i] = array[j];
	array[j] = tmp;
	print_array(array, size);
}

/**
 * lomuto_partition - Partitions array using Lomuto scheme
 * @array: Pointer to the array
 * @size: Number of elements in the array
 * @low: Lower bound index
 * @high: Upper bound index (pivot)
 *
 * Return: Final pivot index
 */
static int lomuto_partition(int *array, size_t size, int low, int high)
{
	int pivot;
	int i;
	int j;

	pivot = array[high];
	i = low;

	for (j = low; j < high; j++)
	{
		if (array[j] < pivot)
		{
			swap_and_print(array, size, i, j);
			i++;
		}
	}

	swap_and_print(array, size, i, high);
	return (i);
}

/**
 * quick_sort_recursive - Recursively sorts partitions around the pivot
 * @array: Pointer to the array
 * @size: Number of elements in the array
 * @low: Lower bound index
 * @high: Upper bound index
 */
static void quick_sort_recursive(int *array, size_t size, int low, int high)
{
	int pivot_index;

	if (low >= high)
		return;

	pivot_index = lomuto_partition(array, size, low, high);
	quick_sort_recursive(array, size, low, pivot_index - 1);
	quick_sort_recursive(array, size, pivot_index + 1, high);
}
