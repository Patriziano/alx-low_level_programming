#include "main.h"

/**
 * swap_int - swapping the values of two integers.
 * @a: first integer.
 * @b: second integer.
 * Return: no return.
 */
void swap_int(int *a, int *b)
{
	int y = *a;
	*a = *b;
	*b = y;
}
