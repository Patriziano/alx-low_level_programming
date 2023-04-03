#include "lists.h"
#include <stdlib.h>
#include <stddef.h>

/**
*add_nodeint_end - function that adds a new node at the end of a linked list
*@head: Pointer that points to the head of the linked list
*@n: integer
*
*Return: Address of the new element
*/
listint_t *add_nodeint_end(listint_t **head, const int n)
{
	listint_t *end_node, *final_node;

	end_node = malloc(sizeof(listint_t));
	if (end_node == NULL)
	{
		return (NULL);
	}
	end_node->n = n;
	end_node->next = NULL;

	if (*head == NULL)
	{
		*head = end_node;
		return (end_node);
	}

	final_node = *head;
	while (final_node->next != NULL)
	{
		final_node = final_node->next;
	}
	final_node->next = end_node;
	return (end_node);
}
