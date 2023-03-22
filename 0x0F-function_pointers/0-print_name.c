#include "function_pointers.h"

/**
*print_name - function that prints a name
*@name: The name input
*@f: function pointer
*
*Return: Nothing
*/
void print_name(char *name, void (*f)(char *))
{
	if (f && name)
	f(name);
}
