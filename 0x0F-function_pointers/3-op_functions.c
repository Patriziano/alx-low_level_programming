#include "calc.h"
#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>

/**
*op_add - calculates sum of given numbers
*@a: first input number
*@b: second input number
*
*Return: 0 Always
*/
int op_add(int a, int b)
{
	return (a + b);
}

/**
*op_sub - calculates difference of given numbers
*@a: first input number
*@b: second input number
*
*Return: 0 Always
*/
int op_sub(int a, int b)
{
	return (a - b);
}

/**
*op_mul - calculates product of given numbers
*@a: first input number
*@b: second input number
*
*Return: 0 Always
*/
int op_mul(int a, int b)
{
	return (a * b);
}


/**
*op_div - calculates division of given numbers
*@a: first input number
*@b: second input number
*
*Return: 0 Always
*/
int op_div(int a, int b)
{
	if (b == 0)
	{
		printf("Error\n");
		exit(100);
	}
	return (a / b);
}

/**
*op_mod - calculates remainder of division of given numbers
*@a: first input number
*@b: second input number
*
*Return: 0 Always
*/
int op_mod(int a, int b)
{
	if (b == 0)
	{
		printf("Error\n");
		exit(100);
	}
	return (a % b);
}
