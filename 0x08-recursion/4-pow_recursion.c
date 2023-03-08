#include "main.h"

/**
*_pow_recursion - recursive function of the value of x raised to the power of y
*@x: first integer
*@y: second integer
*
*Return: -1 if y is lower than zero
*/
int _pow_recursion(int x, int y)
{
	if (y < 0)
	{
		return (-1);
	}
	else if (y == 0)
	{
		return (1);
	}
	else
	{
	return (x * _pow_recursion(x, y - 1));
	}
}	
