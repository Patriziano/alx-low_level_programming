#include "main.h"

/**
*_sqrt_recursion - function that returns the natural square root of a number
*sqrt_helper - searches for square root
*@n: number to find square root of
*@high: upper search range
*@low: lower search range
*Return: -1 if n does not have a natural square root
*/
int sqrt_helper(int n, int low, int high);
int _sqrt_recursion(int n)
{
	if (n < 0)
	{
		return (-1);
	}
	else if (n == 0)
	{
		return (0);
	}
	else if (n == 1)
	{
		return (1);
	}
	else
	{
		return (sqrt_helper(n, 1, n));
	}
}
/**
*sqrt_helper - searches for square root
*@high: upper search range
*@low: lower search range
*@n: number to find square root of
*Return: natural square root of n
*/
int sqrt_helper(int n, int low, int high)
{
	int mid = (low + high) / 2;
	int square = mid * mid;

	if (square == n)
	{
		return (mid);
	}
	else if (low == high)
	{
		return (-1);
	}
	else if (square < n)
	{
		return (sqrt_helper(n, mid + 1, high));
	}
	else
	{
		return (sqrt_helper(n, low, mid));
	}
}
