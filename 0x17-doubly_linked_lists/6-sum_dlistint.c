#include "lists.h"

/**
 * sum_dlistint - Returns the sum of all the data in a doubly linked list.
 * @head: A pointer to the head of the list.
 * Return: 0 If link is empty else the sum of all data in the list.
 */

int sum_dlistint(dlistint_t *head)
{
	dlistint_t *current = head;
	int total = 0;

	while (current != NULL)
	{
		total += current->n;
		current = current->next;
	}

	return (total);
}
