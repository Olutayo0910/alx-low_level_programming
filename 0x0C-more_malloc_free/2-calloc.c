#include "main.h"
#include <stdlib.h>

/**
 * _calloc - Allocates memory for an array using malloc.
 * @nmemb: Number of elements in the array.
 * @size: Size of each element in bytes.
 *
 * Return: Pointer to the allocated memory, or NULL on failure.
 */
void *_calloc(unsigned int nmemb, unsigned int size)
{
	void *allocated_mem;
	unsigned int total_size;

	if (nmemb == 0 || size == 0)
		return (NULL);

	total_size = nmemb * size;

	allocated_mem = malloc(total_size);

	if (allocated_mem == NULL)
		return (NULL);

	/* Set the allocated memory to zero */
	char *mem_ptr = allocated_mem;
	unsigned int i;

	for (i = 0; i < total_size; i++)
		mem_ptr[i] = 0;

	return (allocated_mem);
}
