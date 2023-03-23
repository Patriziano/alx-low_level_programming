#include "variadic_functions.h"
#include <stdarg.h>
#include <stdio.h>

/**
*print_numbers - function that prints numbers
*@separator: string to be printed between numbers
*@n: number of integers passed to the function
*
*Return: Always 0
*/
void print_numbers(const char *separator, const unsigned int n, ...)
{
	va_list ap;
	unsigned int i;
	int num;

	va_start(ap, n);

	for (i = 0; i < n; i++)
	{
		num = va_arg(ap, int);
		printf("%d", num);


		if (i != n - 1 && separator != NULL)
		{
			printf("%s", separator);
		}
	}

	va_end(ap);

	printf("\n");
}
