#include "lists.h"
#include <stdlib.h>

/**
 *insert_nodeint_at_index - function that inserts a new node
 *at a given position
 *@head: pointer to the linked list
 *@idx: i ndex of the list
 *@n: integer to be stored
 *
 *Return: Always 0
*/
listint_t *insert_nodeint_at_index(listint_t **head, unsigned int idx, int n)
{
	unsigned int l;
	listint_t *latest, *former, *current;

	former = NULL;
	current = *head;

	if (head == NULL)
	{
		return (NULL);
	}
	latest = malloc(sizeof(listint_t));
	if (latest == NULL)
	{
		return (NULL);
	}
	latest->n = n;
	latest->next = NULL;

	if (idx == 0)
	{
		latest->next = *head;
		*head = latest;
		return (latest);
	}
	for (l = 0; l < idx && current != NULL; l++)
	{
		former = current;
		current = current->next;
	}

	if (l != idx)
		return (NULL);

	former->next = latest;
	latest->next = current;

	return (latest);
}
