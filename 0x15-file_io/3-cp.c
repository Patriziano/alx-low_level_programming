#include "main.h"
#include <stdio.h>

/**
*open_file - function to check if file can be opened
*@file_from: file source
*@file_to: file destination
*@argv: argument vector
*
*Return: Nothing
*/
void open_file(int file_from, int file_to, char *argv[])
{
	if (file_from < 0)
	{
		dprintf(STDERR_FILENO, "Error; can't read from file %s\n", argv[1]);
		exit(98);
	}
	if (file_to < 0)
	{
		dprintf(STDERR_FILENO, "Error: can't read to %s\n", argv[2]);
		exit(99);
	}
}

/**
*main - main file
*@argc: argument count
*@argv: argument vector
*
*Return: Always 0
*/
int main(int argc, char *argv[])
{
	int file_from, file_to, exit_error;
	ssize_t read_bytes, cp;
	char buffer[1024];

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "%s\n", "Usage: cp file_from file_to");
		exit(97);
	}

	file_from = open(argv[1], O_RDONLY);
	file_to = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC | O_APPEND, 0664);
	open_file(file_from, file_to, argv);

	read_bytes = 1024;
	while (read_bytes == 1024)
	{
		read_bytes = read(file_from, buffer, 1024);
		if (read_bytes < 0)
			open_file(-1, 0, argv);
		cp = write(file_to, buffer, read_bytes);
		if (cp < 0)
			open_file(0, -1, argv);
	}

	exit_error = close(file_from);
	if (exit_error < 0)
	{
		dprintf(STDERR_FILENO, "Error: can't close fd %d\n", file_from);
		exit(100);
	}

	exit_error = close(file_to);
	if (exit_error < 0)
	{
		dprintf(STDERR_FILENO, "Error: can't close fd %d\n", file_from);
		exit(100);
	}
	return (0);
}
