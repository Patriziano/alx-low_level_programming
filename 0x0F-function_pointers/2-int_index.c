#include "function_pointers.h"

/**
*int_index - function that searches for an integer
*@:cmp: pointer to the function
*@array: array name
*@size: number of elements in the array
*
*Return: -1 if no element matches or size <= 0
*/
int int_index(int *array, int size, int (*cmp)(int))
{
	int i;

	if (array && cmp)
	{
		if (size <= 0)
		{
			return (-1);
		}
		for (i = 0; i < size; i++)
		{
			if (cmp(array[i]) != 0)
			return (i);
		}
	}
	return (-1);
}
