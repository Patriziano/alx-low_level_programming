#include "lists.h"
#include <stdio.h>
#include <stdlib.h>

/**
*list_len - function that prints the number of element in a linked list
*@h: pointer to the head
*
*Return: the number of element in a linked list
*/
size_t list_len(const list_t *h)
{
	const list_t *current;

	size_t count;

	count = 0;

	current  = h;

	/* traverse the list until end is reached*/
	while (current != NULL)
	{
		count++;
		current = current->next;
	}
	return (count);
}
