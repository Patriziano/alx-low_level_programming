#include "main.h"

/**
*get_endianness - function that checks the endianness
*
*Return: 0 if BE, 1 if LE
*/
int get_endianness(void)
{
	int num;
	char *byte;

	num = 0x034563978;
	byte = (char *)&num;

	if (*byte == 0x078)
	{
		return (1);
	}
	else
	{
		return (0);
	}
}
