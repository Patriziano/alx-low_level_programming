#include "lists.h"
#include <stdlib.h>

/**
 *free_listint2 - frees a linked list
 *@head: pointer that points to the linked list
 *
 *Return: Always 0
 */
void free_listint2(listint_t **head)
{
	listint_t *new;

	if (head == NULL)
	{
		return;
	}

	while (*head != NULL)
	{
		new = *head;
		*head = (*head)->next;
		free(new);
	}
	*head = NULL;
}



