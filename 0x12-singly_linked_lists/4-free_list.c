#include "lists.h"
#include <stdlib.h>

/**
*free_list - frees a list_t list
*@head: pointer to the first node
*
*Return: Nothing
*/
void free_list(list_t *head)
{
	list_t *current;

	while ((current = head) != NULL)
	{
		head = head->next;
		free(current->str);
		free(current);
	}
}
