#include <stdio.h>
#include <stdlib.h>

/**
*print_opcodes -  prints the opcodes of its own main function
*@n: number of bytes
*
*Return: 0 Always
*/
void print_opcodes(int n)
{
	unsigned char *p = (unsigned char *)&print_opcodes;
	unsigned int i;

	for (i = 0; i < n; i++)
	{
		printf("%02x", *(p + i));
	}
	if ((i + 1) % 2 == 0 && i != n - 1)
	{
		printf(" ");
	}
	printf("\n");
}

/**
*main - checks the program is invocked by one argument
*@argc: number of argument
*@argv: argument vector
*
*Return: Nothing
*/
int main(int argc, char *argv[])
{
	int n;

	if (argc != 2)
	{
		printf("Error\n");
		return (1);
	}
	n  = atoi(argv[1]);
	if (n <= 0)
	{
		printf("Error\n");
		return (2);
	}
	print_opcodes(n);
	return (0);
}
