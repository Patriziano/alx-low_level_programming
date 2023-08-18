#include "lists.h"

/**
* dlistint_len - prints all the elements of a doubly linked list
* @h: head that points to the first node
* Return: Number of nodes
*/

size_t dlistint_len(const dlistint_t *h)
{
	size_t node_counter = 0;

	while (h != NULL)
	{
		h = h->next;
		node_counter++;
	}

	return (node_counter);
}
