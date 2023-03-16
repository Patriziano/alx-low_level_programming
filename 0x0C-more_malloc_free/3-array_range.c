#include "main.h"
#include <stdlib.h>
#include <string.h>

/**
*array_range - creates an array of integer
*@min: minimum integer
*@max: maximum integer
*
*Return: pointer to the newly created array
*/

int *array_range(int min, int max)
{
	int *arr, size;
	int i;

	if (min > max)
	{
		return (NULL);
	}
	size = (max - min) + 1;
	arr = malloc(size * sizeof(int));

	if (arr == NULL)
	{
		return (NULL);
	}
	for (i = 0; i < size; i++, min++)
	{
		arr[i] = min;
	}
	return (arr);
}
