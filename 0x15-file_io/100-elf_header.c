#include "main.h"

/**
 * display_class - This is a function that display class
 * @e_ident: pointer
 * Return: Nothing
 */

void display_class(unsigned char *e_ident)
{
	printf("  Class:                             ");

	switch (e_ident[EI_CLASS])
	{
	case ELFCLASSNONE:
		printf("none\n");
		break;
	case ELFCLASS32:
		printf("ELF32\n");
		break;
	case ELFCLASS64:
		printf("ELF64\n");
		break;
	default:
		printf("<unknown: %x>\n", e_ident[EI_CLASS]);
	}
}


/**
 * display_magic - a function that prints magic
 * @e_ident: pointer
 * Return: Nothing
 */

void display_magic(unsigned char *e_ident)
{
	int len;

	printf("  Magic:   ");

	for (len = 0; len < EI_NIDENT; len++)
	{
		printf("%02x", e_ident[len]);

		if (len == EI_NIDENT - 1)
			printf("\n");
		else
			printf(" ");
	}
}

/**
 * display_data - A function for data
 * @e_ident: pointer
 * Return: Nothing
 */

void display_data(unsigned char *e_ident)
{
	printf("  Data:                              ");

	switch (e_ident[EI_DATA])
	{
	case ELFDATANONE:
		printf("none\n");
		break;
	case ELFDATA2LSB:
		printf("2's complement, little endian\n");
		break;
	case ELFDATA2MSB:
		printf("2's complement, big endian\n");
		break;
	default:
		printf("<unknown: %x>\n", e_ident[EI_CLASS]);
	}
}

/**
 * display_version - This is a function that displays version
 * @e_ident: This is a pointer
 * Return: Nothing
 */

void display_version(unsigned char *e_ident)
{
	printf("  Version:                           %d", e_ident[EI_VERSION]);
	switch (e_ident[EI_VERSION])
	{
		case EV_CURRENT:
			printf(" (current)\n");
			break;
		default:
			printf("\n");
			break;
	}
}


/**
 * display_osabi - This is a function that displays osabi
 * @e_ident: This is a pointer
 * Return: Nothing
 */

void display_osabi(unsigned char *e_ident)
{
	printf("  OS/ABI:                            ");

	switch (e_ident[EI_OSABI])
	{
	case ELFOSABI_NONE:
		printf("UNIX - System V\n");
		break;
	case ELFOSABI_HPUX:
		printf("UNIX - HP-UX\n");
		break;
	case ELFOSABI_NETBSD:
		printf("UNIX - NetBSD\n");
		break;
	case ELFOSABI_LINUX:
		printf("UNIX - Linux\n");
		break;
	case ELFOSABI_SOLARIS:
		printf("UNIX - Solaris\n");
		break;
	case ELFOSABI_IRIX:
		printf("UNIX - IRIX\n");
		break;
	case ELFOSABI_FREEBSD:
		printf("UNIX - FreeBSD\n");
		break;
	case ELFOSABI_TRU64:
		printf("UNIX - TRU64\n");
		break;
	case ELFOSABI_ARM:
		printf("ARM\n");
		break;
	case ELFOSABI_STANDALONE:
		printf("Standalone App\n");
		break;
	default:
		printf("<unknown: %x>\n", e_ident[EI_OSABI]);
	}
}

/**
 * elf_check - a function to to check elf
 * @e_ident: a pointer
 * Return: Nothing;
 */

void elf_check(unsigned char *e_ident)
{
	int len;

	for (len = 0; len < 4; len++)
	{
		if (e_ident[len] != 127 &&
		    e_ident[len] != 'E' &&
		    e_ident[len] != 'L' &&
		    e_ident[len] != 'F')
		{
			dprintf(STDERR_FILENO, "Error: Not an ELF file\n");
			exit(98);
		}
	}
}

/**
 * display_abi - This is a function that displats abi
 * @e_ident: The n
 * Return: Nothing
 */
void display_abi(unsigned char *e_ident)
{
	printf("  ABI Version:                       %d\n",
	       e_ident[EI_ABIVERSION]);
}

/**
 * display_type - This is a function to show type
 * @e_type: The n
 * @e_ident: this is pointer
 * Return: Nothinh
 */

void display_type(unsigned int e_type, unsigned char *e_ident)
{
	if (e_ident[EI_DATA] == ELFDATA2MSB)
		e_type >>= 8;

	printf("  Type:                              ");

	switch (e_type)
	{
	case ET_NONE:
		printf("NONE (None)\n");
		break;
	case ET_REL:
		printf("REL (Relocatable file)\n");
		break;
	case ET_EXEC:
		printf("EXEC (Executable file)\n");
		break;
	case ET_DYN:
		printf("DYN (Shared object file)\n");
		break;
	case ET_CORE:
		printf("CORE (Core file)\n");
		break;
	default:
		printf("<unknown: %x>\n", e_type);
	}
}

/**
 * display_entry - This is a function that displays emrty
 * @e_entry: The n
 * @e_ident: The pointer
 * Return: Nothing
 */

void display_entry(unsigned long int e_entry, unsigned char *e_ident)
{
	printf("  Entry point address:               ");

	if (e_ident[EI_DATA] == ELFDATA2MSB)
	{
		e_entry = ((e_entry << 8) & 0xFF00FF00) |
			((e_entry >> 8) & 0xFF00FF);
		e_entry = (e_entry << 16) | (e_entry >> 16);
	}

	if (e_ident[EI_CLASS] == ELFCLASS32)
		printf("%#x\n", (unsigned int)e_entry);

	else
		printf("%#lx\n", e_entry);
}

/**
 * to_close - This is a function that close
 * @fo: the int value
 * Return: Nothinh
 */
void to_close(int fo)
{
	if (close(fo) == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fo);
		exit(98);
	}
}

/**
 * main - This a function for elf header
 * @ac: This is argumnet count
 * @av: This is the nuber of array
 * Return: Always 0
 */

int main(int ac, char **av)
{
	int fd, reading;
	Elf64_Ehdr *header;
	(void)ac;

	fd = open(av[1], O_RDONLY);
	if (fd == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read file %s\n", av[1]);
		exit(98);
	}
	header = malloc(sizeof(Elf64_Ehdr));
	if (header == NULL)
	{
		to_close(fd);
		dprintf(STDERR_FILENO, "Error: Can't read file %s\n", av[1]);
		exit(98);
	}
	reading = read(fd, header, sizeof(Elf64_Ehdr));
	if (reading == -1)
	{
		free(header);
		to_close(fd);
		dprintf(STDERR_FILENO, "Error: `%s`: No such file\n", av[1]);
		exit(98);
	}
	elf_check(header->e_ident);
	printf("ELF Header:\n");
	display_magic(header->e_ident);
	display_class(header->e_ident);
	display_data(header->e_ident);
	display_version(header->e_ident);
	display_osabi(header->e_ident);
	display_abi(header->e_ident);
	display_type(header->e_type, header->e_ident);
	display_entry(header->e_entry, header->e_ident);

	free(header);
	to_close(fd);
	return (0);
}
