/**
 * free_listint_safe - frees a listint_t list.
 * @h: double pointer to head of list
 *
 * Return: the size of the list that was free’d
 */
size_t free_listint_safe(listint_t **h)
{
    size_t size = 0;
    listint_t *current, *next;

    if (!h || !*h)
        return (0);

    current = *h;
    while (current)
    {
        size++;
        next = current->next;
        free(current);
        if (next >= current)
        {
            *h = NULL;
            return (size);
        }
        current = next;
    }

    *h = NULL;
    return (size);
}
