#include "main.h"

/**
*_strstr - function that locates a substring
*@needle: substring
@haystack: string
*
*Return: pointer to the beginning of the located substring, otherwise '\0'
*/
char *_strstr(char *haystack, char *needle)
{
	char *p1, *p2, *p3;

	if (!*needle)
		{
		return (haystack);
		}
		while (*haystack)
		{
			p1 = haystack;
			p2 = needle;
			p3 = haystack;

	while (*p3 && *p2 && (*p3 == *p2))
	{
	p3++;
	p2++;
	}
		if (!*p2)
		{
		return (p1);
		}

		if (!*p3)
			{
			return ('\0');
			}
		haystack++;
		}
	return ('\0');
}
