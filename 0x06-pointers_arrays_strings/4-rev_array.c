#include "main.h"

/**
 * reverse_array - reverse the content of an array of integers
 * @a: an array of integers
 * @n: the number of elements to swap
 *
 * Return: void
 */
void reverse_array(int *a, int n)
{
	int y;
	int i;

	for (i = 0; i < n / 2; i++)
	{
		y = a[i];
		a[i] = a[n - i - 1];
		a[n - i - 1] = y;
	}
}
