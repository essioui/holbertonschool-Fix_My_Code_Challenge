#include <string.h>
#include <stdlib.h>
#include "lists.h"

/**
 * delete_dnodeint_at_index - Delete a node at a specific index from a list
 *
 * @head: A pointer to the pointer to the first element of a list
 * @index: The index of the node to delete
 *
 * Return: 1 on success, -1 on failure
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
    dlistint_t *current;
    dlistint_t *tmp;
    unsigned int i;

    if (*head == NULL)
        return (-1);

    current = *head;

    /* Traverse to the node to delete */
    for (i = 0; i < index && current != NULL; i++)
    {
        current = current->next;
    }

    /* If index is out of range */
    if (current == NULL)
        return (-1);

    /* If deleting the head node */
    if (current->prev != NULL)
        current->prev->next = current->next;
    else
        *head = current->next;

    if (current->next != NULL)
        current->next->prev = current->prev;

    tmp = current;
    free(tmp);

    return (1);
}
