#include <stdio.h>

/**
*main - function that prints its name followed by a new line
*@argc: number of command line argument
*@argv: array that contains the command line arguments
*
*Return: 0 always
*/
int main(int argc __attribute__((unused)), char* argv[])
{
	printf("%s\n", argv[0]);
	return (0);
}
