#include "lists.h"
/**
 * free_list - Frees a list_t list.
 * @head: Pointer to the head of the list.
 * Return: nothing to
 */
void free_list(list_t *head)
{
	list_t *current = head;
	list_t *next_node;

	while (current != NULL)
	{
		next_node = current->next;
		free(current->str);
		free(current);
		current = next_node;
	}
}
