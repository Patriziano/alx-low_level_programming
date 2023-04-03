#include "lists.h"
#include <stdlib.h>
#include <stdio.h>

/**
*add_nodeint - adds a new node at the beginning of a linked list
*@head: pointer that points to the head
*@n: integer
*
*Return: Address of the new node created
*/
listint_t *add_nodeint(listint_t **head, const int n)
{
	listint_t *add_node;

	add_node = malloc(sizeof(listint_t));
	if (add_node == NULL)
	{
		return (NULL);
	}

	add_node->n = n;
	add_node->next = *head;
	*head = add_node;

	return (add_node);
}
