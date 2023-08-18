#include "lists.h"

/**
 * delete_node_at_index - Deletes a given node from the list.
 * @node: The node to be deleted.
 */
void delete_node_at_index(dlistint_t *node)
{
	if (node->prev != NULL)
	{
		node->prev->next = node->next;
	}

	if (node->next != NULL)
	{
		node->next->prev = node->prev;
	}

	free(node);
}

/**
 * find_node_at_index - Finds and returns the node at a given index.
 * @head: The head of the list.
 * @index: The index of the node to be found.
 * Return: The node at the index, or NULL if not found.
 */
dlistint_t *find_node_at_index(dlistint_t *head, unsigned int index)
{
	dlistint_t *current = head;
	unsigned int i;

	for (i = 0; i < index && current != NULL; i++)
	{
		current = current->next;
	}

	return (current);
}

/**
 * delete_dnodeint_at_index - Deletes the node at a given index in a dlistint
 * @head: A pointer to the head of the list.
 * @index: The index of the node to be deleted (0-based).
 * Return: 1 if successful, -1 if the deletion fails.
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
	dlistint_t *node_to_delete, *temp;

	if (*head == NULL)
	{
		return (-1);
	}

	if (index == 0)
	{
		temp = *head;
		*head = (*head)->next;
		if (*head != NULL)
		{
			(*head)->prev = NULL;
		}
		free(temp);
		return (1);
	}

	node_to_delete = find_node_at_index(*head, index);
	if (node_to_delete == NULL)
	{
		return (-1);
	}

	delete_node_at_index(node_to_delete);
	return (1);
}
