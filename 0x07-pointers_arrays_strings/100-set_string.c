#include "main.h"

/**
*set_string - set the value of a pointer to char
*@s: source pointer
*@to: destination address
*
*Return: void
*/

void set_string(char **s, char *to)
{
	*s = to;
}
