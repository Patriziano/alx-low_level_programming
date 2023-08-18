#include "lists.h"

/**
* get_dnodeint_at_index - returns the nth node of a doubly linked list
* @head: pointer to the head of the doubly linked list
* @index: The index of the node to retrieve(from 0)
* Return: NULL if node does not exit
*/

dlistint_t *get_dnodeint_at_index(dlistint_t *head, unsigned int index)
{
	unsigned int node_counter = 0;
	dlistint_t *current = head;

	while (current != NULL && node_counter < index)
	{
		current = current->next;
		node_counter++;
	}

	return (current);
}
