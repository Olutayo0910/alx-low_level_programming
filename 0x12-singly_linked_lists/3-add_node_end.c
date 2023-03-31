#include "lists.h"

/**
 * add_node_end - Adds a new node at the end of a list_t list.
 * @head: Pointer to the head of the list.
 * @str: String to be stored in the new node.
 *
 * Return: Address of the new element, or NULL if it failed.
 */
list_t *add_node_end(list_t **head, const char *str)
{
    list_t *new_node, *last_node;
    unsigned int len = 0;

    /* Calculate the length of the string */
    while (str[len])
        len++;

    /* Allocate memory for the new node */
    new_node = malloc(sizeof(list_t));
    if (new_node == NULL)
        return (NULL);

    /* Fill in the new node */
    new_node->str = strdup(str);
    if (new_node->str == NULL)
    {
        free(new_node);
        return (NULL);
    }
    new_node->len = len;
    new_node->next = NULL;

    /* Traverse the list to find the last node */
    last_node = *head;
    if (last_node != NULL)
    {
        while (last_node->next != NULL)
            last_node = last_node->next;
        last_node->next = new_node;
    }
    else
    {
        *head = new_node;
    }

    return (new_node);
}
