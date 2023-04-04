#include "lists.h"
#include <stdlib.h>

/**
 *get_nodeint_at_index - function that returns the nth node of a linked list
 *@head: pointer to the linked list
 *@index: index of the node
 *
 *Return: ALways 0
*/
listint_t *get_nodeint_at_index(listint_t *head, unsigned int index)
{
	unsigned int j;
	listint_t *nth_node;

	nth_node = head;
	j = 0;

	while (nth_node != NULL && j < index)
	{
		nth_node = nth_node->next;
		j++;
	}
	return (nth_node);
}
