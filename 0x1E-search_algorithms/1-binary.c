#include "search_algos.h"

/**
 * binary_search_recursive - recursive helper function for binary search
 * @array: pointer to the first element of the array to search in
 * @l: left index of the current subarray
 * @r: right index of the current subarray
 * @value: value to search for
 *
 * Return: index where value is located, or -1 if not found
 */
int binary_search_recursive(int *array, size_t l, size_t r, int value)
{
	size_t i;
	if (l <= r)
	{
		size_t mid = l + (r - l) / 2;

		printf("Searching in array: ");
		for (i = l; i <= r; i++)
		{
			if (i < r)
				printf("%d, ", array[i]);
			else
				printf("%d\n", array[i]);
		}
		if (array[mid] == value)
			return (mid);
		if (array[mid] > value)
			return (binary_search_recursive(array, l, mid - 1, value));
		return (binary_search_recursive(array, mid + 1, r, value));
	}
	return (-1);
}

/**
 * binary_search - searches for a value in a sorted array using binary search
 * @array: pointer to the first element of the array to search in
 * @size: number of elements in the array
 * @value: value to search for
 *
 * Return: index where value is located, or -1 if not found
 */
int binary_search(int *array, size_t size, int value)
{
	if (array == NULL)
		return (-1);
	return (binary_search_recursive(array, 0, size - 1, value));
}
