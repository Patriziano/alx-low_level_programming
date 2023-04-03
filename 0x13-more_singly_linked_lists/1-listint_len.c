#include "lists.h"
#include <stdlib.h>
#include <stdio.h>

/**
*listint_len - returns the number of elements in a linked list
*@h: head of the linked list pointer
*
*Return: the number of elemets
*/
size_t listint_len(const listint_t *h)
{
	size_t count;
	const listint_t *new;

	new = h;
	count = 0;

	while (new != NULL)
	{
		count++;
		new = new->next;
	}
	return (count);
}
