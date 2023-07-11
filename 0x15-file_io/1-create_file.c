#include "main.h"
#include <string.h>

/**
*create_file - function that creates a file
*@filename: name of the file
*@text_content: Null terminated string
*
*Return: 1 for success, -1 on failure
*/
int create_file(const char *filename, char *text_content)
{
	int fp;
	ssize_t cf;

	if (filename == NULL)
	{
		return (-1);
	}
	fp = open(filename, O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);

	if (fp < 0)
	{
		return (-1);
	}

	if (text_content != NULL)
	{
		cf = write(fp, text_content, strlen(text_content));

		if (cf < 0)
		{
			close(fp);
			return (-1);
		}
	}
	close(fp);
	return (1);
}
