#include "lists.h"
/**
 * list_len - Returns the number of elements in a linked list.
 * @h: pointer to the list
 *
 * Return: number of elements in a linked list
 */
size_t list_len(const list_t *h)
{
	size_t count = 0;

	while (h != NULL)
	{
		h = h->next;
		count++;
	}
	return (count);
}
