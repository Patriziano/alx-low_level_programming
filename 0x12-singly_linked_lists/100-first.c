#include "lists.h"
#include <stdio.h>

/**
*print_quote - function executed before main
*
*Return: Always 0
*/
void __attribute__ ((constructor)) print_quote()
{
	printf("You're beat! and yet, you must allow,\n");
	printf("I bore my house upon my back!\n");
}

