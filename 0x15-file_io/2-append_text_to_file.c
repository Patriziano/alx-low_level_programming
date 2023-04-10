#include "main.h"
#include <string.h>
#include <stdio.h>

/**
*append_text_to_file - function that appends text at the end of a file
*@filename: name of the file
*@text_content: null terminated string
*
*Return: 1 on success, -1 on failure
*/
int append_text_to_file(const char *filename, char *text_content)
{
	int t_length;
	FILE *fp;

	if (filename == NULL)
	{
		return (-1);
	}
	fp = fopen(filename, "a");
	if (fp == NULL)
	{
		return (-1);
	}
	if (text_content != NULL)
	{
		t_length = strlen(text_content);
		fwrite(text_content, sizeof(char), t_length, fp);
	}
	fclose(fp);
	return (1);
}
