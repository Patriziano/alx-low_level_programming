#include "lists.h"

/**
* print_dlistint - prints all the elements of a doubly linked list
* @h: head that points to the first node
* Return: Number of nodes
*/

size_t print_dlistint(const dlistint_t *h)
{
	size_t node_counter = 0;

	while (h != NULL)
	{
		printf("%d\n", h->n);
		h = h->next;
		node_counter++;
	}

	return (node_counter);
}
