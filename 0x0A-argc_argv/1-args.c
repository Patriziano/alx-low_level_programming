#include <stdio.h>

/**
*main - program that prints the number of arguments passed into it
*@argc: number of command line argument
*@argv: array that contains the program line arguments
*
*Return: 0 - always
*/
int main(int argc, char *argv[] __attribute__((unused)))
{
	int num_args = argc - 1;

	printf("%d\n", num_args);
	return (0);
}
