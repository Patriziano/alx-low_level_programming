#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <elf.h>

/**
 * print_addr - prints address
 * @ptr: magic.
 * Return: no return.
 */
void print_addr(char *ptr)
{
	int i;
	int start;
	char systemtem;

	printf("  Entry point address:               0x");

	systemtem = ptr[4] + '0';
	if (systemtem == '1')
	{
		start = 26;
		printf("80");
		for (i = start; i >= 22; i--)
		{
			if (ptr[i] > 0)
				printf("%x", ptr[i]);
			else if (ptr[i] < 0)
				printf("%x", 256 + ptr[i]);
		}
		if (ptr[7] == 6)
			printf("00");
	}

	if (systemtem == '2')
	{
		start = 26;
		for (i = start; i > 23; i--)
		{
			if (ptr[i] >= 0)
				printf("%02x", ptr[i]);

			else if (ptr[i] < 0)
				printf("%02x", 256 + ptr[i]);

		}
	}
	printf("\n");
}

/**
 * print_var - prints var
 * @ptr: magic.
 * Return: no return.
 */
void print_var(char *ptr)
{
	char var = ptr[16];

	if (ptr[5] == 1)
		var = ptr[16];
	else
		var = ptr[17];

	printf("  Type:                              ");
	if (var == 0)
		printf("NONE (No file var)\n");
	else if (var == 1)
		printf("REL (Relocatable file)\n");
	else if (var == 2)
		printf("EXEC (Executable file)\n");
	else if (var == 3)
		printf("DYN (Shared object file)\n");
	else if (var == 4)
		printf("CORE (Core file)\n");
	else
		printf("<unknown: %x>\n", var);
}

/**
 * print_osabi - prints osabi
 * @ptr: magic.
 * Return: no return.
 */
void print_osabi(char *ptr)
{
	char osabi = ptr[7];

	printf("  OS/ABI:                            ");
	if (osabi == 0)
		printf("UNIX - System V\n");
	else if (osabi == 2)
		printf("UNIX - NetBSD\n");
	else if (osabi == 6)
		printf("UNIX - Solaris\n");
	else
		printf("<unknown: %x>\n", osabi);

	printf("  ABI Version:                       %d\n", ptr[8]);
}


/**
 * print_version - prints version
 * @ptr: magic.
 * Return: no return.
 */
void print_version(char *ptr)
{
	int version = ptr[6];

	printf("  Version:                           %d", version);

	if (version == EV_CURRENT)
		printf(" (current)");

	printf("\n");
}
/**
 * print_data - prints data
 * @ptr: magic.
 * Return: no return.
 */
void print_data(char *ptr)
{
	char data = ptr[5];

	printf("  Data:                              2's complement");
	if (data == 1)
		printf(", little endian\n");

	if (data == 2)
		printf(", big endian\n");
}
/**
 * print_magic - prints magic info.
 * @ptr: magic.
 * Return: no return.
 */
void print_magic(char *ptr)
{
	int bytes;

	printf("  Magic:  ");

	for (bytes = 0; bytes < 16; bytes++)
		printf(" %02x", ptr[bytes]);

	printf("\n");

}

/**
 * check_system - check the version systemtem.
 * @ptr: magic.
 * Return: no return.
 */
void check_system(char *ptr)
{
	char system = ptr[4] + '0';

	if (system == '0')
		exit(98);

	printf("LF Header:\n");
	print_magic(ptr);

	if (system == '1')
		printf("  Class:                             ELF32\n");

	if (system == '2')
		printf("  Class:                             ELF64\n");

	print_data(ptr);
	print_version(ptr);
	print_osabi(ptr);
	print_var(ptr);
	print_addr(ptr);
}

/**
 * check_elf - check if it is an elf file.
 * @ptr: magic.
 * Return: 1 if it is an elf file. 0 if not.
 */
int check_elf(char *ptr)
{
	int addr = (int)ptr[0];
	char E = ptr[1];
	char L = ptr[2];
	char F = ptr[3];

	if (addr == 127 && E == 'E' && L == 'L' && F == 'F')
		return (1);

	return (0);
}

/**
 * main - check the code for Holberton School students.
 * @argc: number of arguments.
 * @argv: arguments vector.
 * Return: Always 0.
 */
int main(int argc, char *argv[])
{
	int fp, read_bytes;
	char ptr[27];

	if (argc != 2)
	{
		dprintf(STDERR_FILENO, "Usage: elf_header elf_filename\n");
		exit(98);
	}

	fp = open(argv[1], O_RDONLY);

	if (fp < 0)
	{
		dprintf(STDERR_FILENO, "Err: file can not be open\n");
		exit(98);
	}

	lseek(fp, 0, SEEK_SET);
	read_bytes = read(fp, ptr, 27);

	if (read_bytes == -1)
	{
		dprintf(STDERR_FILENO, "Err: The file can not be read\n");
		exit(98);
	}

	if (!check_elf(ptr))
	{
		dprintf(STDERR_FILENO, "Err: It is not an ELF\n");
		exit(98);
	}

	check_system(ptr);
	close(fp);

	return (0);
}
