#include "main.h"
#include <elf.h>
#include <errno.h>

/**
*display_Error_And_Exit - Function to display and exit any error
*encountered to the stderr
*@message: error message
*
*Return: Nothing
*/
int display_Error_And_Exit(const char *message)
{
	fprintf(stderr, "Error: %s\n", message);
	exit(98);
}
	
/**
*open_Elf_File - function to open the Elf file
*@filename: name of the file to be open
*
*Return: Nothing
*/
int open_Elf_File(const char *filename)
{
	int fp;

	fp = open(filename, O_RDONLY);
	if (fp < 0)
	{
		display_Error_And_Exit("Failed to open file");
	}
	return (fp);
}

/**
*read_Elf_Header - function that reads the Elf header
*@fp: file descriptor
*@elf_header: the header of elf
*
*Return: Nothing
*/
void read_Elf_Header(int fp, Elf64_Ehdr *elf_header)
{
	ssize_t read_bytes;

	read_bytes = read(fp, &elf_header, sizeof(elf_header));

	if (read_bytes != sizeof(elf_header))
	{
		display_Error_And_Exit("failed to read ELF header");
	}
}

/**
*check_Elf_Magic - check for Elf magic files
*@elf_header: elf header file
*
*Return: Nothing
*/
void check_Elf_Magic(const Elf64_Ehdr *elf_header)
{
	if (memcmp(elf_header->e_ident, ELFMAG, SELFMAG) != 0)
	{
		display_Error_And_Exit("File is not an Elf file");
	}
}

/**
*display_Elf_Header_Info - function that displays the header info
*@elf_header: header of elf
*
*Return: Nothing
*/
void display_Elf_Header_Info(const Elf64_Ehdr *elf_header)
{
	printf("ELF Header: \n");
	printf("Magic: %02x %02x %02x %02x\n", elf_header->e_ident[0],
	elf_header->e_ident[1], elf_header->e_ident[2], elf_header->e_ident[3]);
	printf("Class: %d-bit\n", elf_header->e_ident[EI_CLASS] == ELFCLASS32 ? 32 : 64);
	printf("Data: %s\n", elf_header->e_ident[EI_DATA] == ELFDATA2LSB ? "2's complement, little-endian" : "2's complement, big-endian");
	printf("Version: %d\n", elf_header->e_ident[EI_VERSION]);
	printf("OS/ABI: %d\n", elf_header->e_ident[EI_OSABI]);
	printf("ABI Version: %d\n", elf_header->e_ident[EI_ABIVERSION]);
	printf("Type: %d\n", elf_header->e_type);
	printf("Entry point address: 0x%lx\n", elf_header->e_entry);
}

/**
*main - the main function
*@argc: argument count
*@argv: argument vector
*
*Return: 0 always
*/

int main(int argc, char *argv[])
{
	int fp;
	const char *filename;
	Elf64_Ehdr elf_header;

	if (argc != 2)
	{
		display_Error_And_Exit("Number of arguments not valid");
	}

	filename = argv[1];
	fp = open_Elf_File(filename);


	read_Elf_Header(fp, &elf_header);

	check_Elf_Magic(&elf_header);

	display_Elf_Header_Info(&elf_header);

	close(fp);

	return (0);
}

