#include "lists.h"
#include <stdlib.h>

/**
 *pop_listint - a function that deletes the head node of a linked list
 *@head: the head to the pointer
 *
*Return: head node's of data(n)
*/
int pop_listint(listint_t **head)
{
	int num;
	listint_t *link;

	num = 0;

	if (*head == NULL)
	{
		return (num);
	}
	link = *head;
	num = link->n;
	*head = (*head)->next;
	free(link);
	return (num);
}
