#include "lists.h"
#include <stdlib.h>

/**
 * delete_dnodeint_at_index - Delete a node at a specific index from a list
 *
 * @head: A pointer to the first element of the list
 * @index: The index of the node to delete
 *
 * Return: 1 on success, -1 on failure
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
    dlistint_t *current;
    unsigned int i;

    if (*head == NULL)
    {
        return (-1);
    }

    current = *head;

    /* Traverse to the node to delete */
    for (i = 0; current != NULL && i < index; i++)
    {
        current = current->next;
    }

    /* If the node was not found */
    if (current == NULL)
    {
        return (-1);
    }

    /* Update the previous node's next if it's not the first node */
    if (current->prev != NULL)
    {
        current->prev->next = current->next;
    }
    else
    {
        /* Update the head if deleting the first node */
        *head = current->next;
    }

    /* Update the next node's prev if it's not NULL */
    if (current->next != NULL)
    {
        current->next->prev = current->prev;
    }

    /* Free the memory of the node to be deleted */
    free(current);

    return (1);
}
