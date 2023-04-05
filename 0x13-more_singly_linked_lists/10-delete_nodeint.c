#include "lists.h"
#include <stdlib.h>

/**
 *delete_nodeint_at_index - function that deletes the node at index
 *@head: pointer to the linked list
 *@index: index of the node that should be deleted
 *
*Return: 1 if succeeded, -1 if failed
 */
int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
	unsigned int j;
	listint_t *deleted_node, *current_node;

	if (head == NULL || *head == NULL)
		return (-1);

	if (index == 0)
	{
		current_node = *head;
		*head = (*head)->next;
		free(current_node);
		return (1);
	}
	
	deleted_node = NULL;
	current_node = *head;
	for (j = 0; j < index && current_node != NULL; j++)
	{
		deleted_node = current_node;
		current_node = current_node->next;
	}
	if (current_node == NULL)
		return (-1);
	if (deleted_node != NULL)
		deleted_node->next = current_node->next;
	else
		*head = current_node->next;

	free(current_node);
	return (1);
}
