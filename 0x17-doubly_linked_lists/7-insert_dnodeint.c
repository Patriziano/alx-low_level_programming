#include "lists.h"

/**
 * insert_dnodeint_at_index - Inserts a node at a given position in a doubly linked list.
 * @head: A pointer to the head of the list.
 * @idx: The index at which the new node should be inserted (0-based).
 * @n: The value to store in the new node.
 * Return: The address of the new node, or NULL if the insertion fails.
 */
dlistint_t *insert_dnodeint_at_index(dlistint_t **h, unsigned int idx, int n)
{
	dlistint_t *new_node = malloc(sizeof(dlistint_t));
	dlistint_t *current = *h;
	unsigned int i;

	if (new_node == NULL)
	{
		return (NULL);
	}

	new_node->n = n;
    
	if (idx == 0)
	{
		new_node->prev = NULL;
		new_node->next = *h;
		if (*h != NULL)
		{
			(*h)->prev = new_node;
		}
		*h = new_node;
		return new_node;
	}

	for (i = 0; i < idx - 1 && current != NULL; i++)
	{
		current = current->next;
	}

	if (current == NULL)
	{
		free(new_node);
		return (NULL);
	}

	new_node->prev = current;
	new_node->next = current->next;

	if (current->next != NULL)
	{
		current->next->prev = new_node;
	}

	current->next = new_node;

	return new_node;
}
