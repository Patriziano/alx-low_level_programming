#include "lists.h"
#include <stdio.h>
#include <stdlib.h>

/**
*size_t print_list - prints all the elements of a list
*@list_t: The list to be printed
*@h: pointer to the first node
*
*Return: Number of nodes
*/
size_t print_list(const list_t *h)
{
	size_t count;

	count = 0;
	
	while (h != NULL)
	{
		if (h->str != NULL)
		{
			printf("[%u] %s\n", h->len, h->str);
		}
		else
		{
			printf("[0] (nil)\n");
		}

		count++;
		h = h->next;
	}
	return (count);
}
