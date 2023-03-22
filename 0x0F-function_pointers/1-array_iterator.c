#include "function_pointers.h"

/**
*array_iterator - function that executes a function
*@array: array name
*@size: size of the array
*@action: pointer to the function
*
*Return: Nothing
*/
void array_iterator(int *array, size_t size, void (*action)(int))
{
	unsigned int i;

	if (!action || !array)
	{
		return;
	}
	for (i = 0; i < size; i++)
	{
		action(array[i]);
	}
}
