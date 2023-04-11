#include "main.h"

/**
*read_textfile - function that reads a text file
*and prints it to the POSIX standard output
*@filename:the name of the text file to be read from
*@letters: number of letters to be read
*
*Return: Nothing
*/
ssize_t read_textfile(const char *filename, size_t letters)
{
	int fp;
	ssize_t read_byte;
	ssize_t wb;
	char *buffer;

	if (filename == NULL)
	{
		return (0);
	}
	fp = open(filename, O_RDONLY);
	if (fp < 0)
	{
		return (0);
	}
	buffer = malloc(sizeof(char) * (letters));
	if (buffer == NULL)
	{
		return (0);
	}
	read_byte = read(fp, buffer, letters);
	wb = write(STDOUT_FILENO, buffer, read_byte);

	close(fp);
	free(buffer);
	return (wb);
}
