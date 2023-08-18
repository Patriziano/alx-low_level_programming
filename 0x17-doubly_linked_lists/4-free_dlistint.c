#include "lists.h"

/**
* free_dlistint - function that frees a doubly linked list
* @head: a pointer that points to the head of the linked list
* Return: Nothing
*/

void free_dlistint(dlistint_t *head)
{
	while (head != NULL)
	{
		dlistint_t *temp = head;

		head = head->next;
		free(temp);
	}
}
