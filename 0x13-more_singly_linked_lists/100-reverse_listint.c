#include "lists.h"
#include <stdlib.h>
#include <string.h>

/**
 *reverse_listint - reverses a linked list
 *@head: pointer to the linked list
 *
 *Return: A pointer to the first node of the reversed list
 */
listint_t *reverse_listint(listint_t **head)
{
	listint_t *old, *reverse;
	listint_t *next;

	old = NULL;
	reverse = *head;

	while (reverse != NULL)
	{
		next = reverse->next;
		reverse->next = old;
		old = reverse;
		reverse = next;
	}
	*head = old;
	return (old);
}
