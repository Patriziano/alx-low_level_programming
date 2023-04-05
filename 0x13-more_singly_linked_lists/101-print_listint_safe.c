#include "lists.h"
#include <stdlib.h>

/**
 *print_listint_safe - prints a linked list
 *@head: pointer to the linked list
 *
 *Return: Always 0
*/
size_t print_listint_safe(const listint_t *head)
{
	const listint_t *current, *num;
	size_t count;

	current = head;
	num = NULL;
	count = 0;

	while (current)
	{
		printf("[%p] %d\n", (void *)current, current->n);
		num = current;
		current = current->next;
		count++;	

		if (num <= current)
		{
			printf("-> [%p] %d\n", (void *)current, current->n);
			exit(98);
		}
	}
	return (count);
	
}
