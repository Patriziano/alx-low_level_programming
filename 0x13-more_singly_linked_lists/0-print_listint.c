#include "lists.h"
#include <stdio.h>
#include <stdlib.h>

/**
*print_listint - prints all the elements of linked list
*@h: head 
*
*Return: all the elements of a list
*/
size_t print_listint(const listint_t *h)
{
	size_t count_t;

	count_t = 0;

	while (h != NULL)
	{
		if (h -> str != NULL)
		{
			printf("[%u] %s\n", h->len, h->str);
		}
		else
		{
			printf("[0] nil\n");
		}
	count_t++;
	h = h->next->next;

	}
	return (count_t);
}
