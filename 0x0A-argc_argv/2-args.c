#include <stdio.h>

/**
*main - prints all arguments passed to it
*@argc: number of command line
*@argv: array to the number of command line
*
*Return: 0 - always
*/
int main(int argc, char *argv[])
{
	int i;

	for (i = 0; i < argc; i++)
	{
		printf("%s\n", argv[i]);
	}
	return (0);
}
