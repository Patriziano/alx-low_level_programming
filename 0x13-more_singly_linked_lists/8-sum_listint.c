#include "lists.h"
#include <stdlib.h>

/**
 *sum_listint - returns the sum of all the data of a linked list
 *@head: pointer to the linked list
 *
 *Return: Always 0
 */
int sum_listint(listint_t *head)
{
	int sum;

	sum = 0;

	while (head != NULL)
	{
		sum = sum + head->n;
		head = head->next;
	}
	return (sum);
}
