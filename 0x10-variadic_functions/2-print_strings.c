#include "variadic_functions.h"
#include <stdarg.h>
#include <stdio.h>

/**
*print_strings - function that prints strings
*@separator: string to be printed between the strings
*@n: number of strings passed to the function
*
*Return: Always 0
*/
void print_strings(const char *separator, const unsigned int n, ...)
{
	va_list ap;
	unsigned int i;
	char *str;

	va_start(ap, n);

	for (i = 0; i < n; i++)
	{
		str = va_arg(ap, char*);

		if (str == NULL)
		{
			printf("(nil)");
		}
		else
		{
			printf("%s", str);
		}

		if (separator != NULL && i != n - 1)
		{
			printf("%s", separator);
		}
	}

	va_end(ap);

	printf("\n");

}
