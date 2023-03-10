#include <stdio.h>
#include <stdlib.h>

/**
* main - program that multiplies two numbers
*@argc: number ofcommand line arguments
*@argv: array that contains the number of command line argument
*Return: 1 if it doesn't receive two arguments
*/
int main(int argc, char *argv[])
{
	int num1, num2, result;

	if (argc != 3)
	{
		printf("Error\n");
		return (1);
	}
	num1 = atoi(argv[1]);
	num2 = atoi(argv[2]);

	result = num1 * num2;
	printf("%d\n", result);

	return (0);
}
