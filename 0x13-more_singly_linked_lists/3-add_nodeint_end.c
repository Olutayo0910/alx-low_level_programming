#include "lists.h"
#include <stdlib.h>


/**
 * add_nodeint_end - adds a new node at the end of a listint_t list
 * @head: pointer to a pointer to the head node
 * @n: integer value to be stored in the new node
 *
 * Return: address of the new node, or NULL if it failed
 */
listint_t *add_nodeint_end(listint_t **head, const int n)
{
    listint_t *new, *last;

    if (head == NULL)
        return (NULL);

    new = malloc(sizeof(listint_t));
    if (new == NULL)
        return (NULL);

    new->n = n;
    new->next = NULL;

    if (*head == NULL)
    {
        *head = new;
        return (new);
    }

    last = *head;
    while (last->next != NULL)
        last = last->next;

    last->next = new;
    return (new);
}
