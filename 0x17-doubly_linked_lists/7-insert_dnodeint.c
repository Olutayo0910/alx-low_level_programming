#include "lists.h"

/**
 * insert_dnodeint_at_index - Inserts a new node at a given position.
 * @h: Pointer to a pointer to the head of the list
 * @idx: Index of the position where the new node should be inserted
 * @n: Value to be added in the new node
 *
 * Return: The address of the new node, or NULL if it failed
 */
dlistint_t *insert_dnodeint_at_index(dlistint_t **h, unsigned int idx, int n)
{
	unsigned int count = 0;
	dlistint_t *new_node, *current;

	if (h == NULL)
		return (NULL);

	if (idx == 0)
		return (add_dnodeint(h, n));

	current = *h;

	while (current != NULL)
	{
		if (count == idx - 1)
		{
			new_node = malloc(sizeof(dlistint_t));
			if (new_node == NULL)
				return (NULL);

			new_node->n = n;
			new_node->next = current->next;
			new_node->prev = current;
			if (current->next != NULL)
				current->next->prev = new_node;
			current->next = new_node;

			return (new_node);
		}
		current = current->next;
		count++;
	}

	return (NULL);
}
