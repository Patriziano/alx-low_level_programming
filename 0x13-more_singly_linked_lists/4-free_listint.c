#include "lists.h"
#include <stdlib.h>

/**
*free_listint - function that frees a linked list
*@head: pointer to the linked list
*
*Return: Always 0
*/
void free_listint(listint_t *head)
{
	listint_t *new;

	while (head != NULL)
	{
		new = head;
		head = head->next;
		free(new);
	}
}
