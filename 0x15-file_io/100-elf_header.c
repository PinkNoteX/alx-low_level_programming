#include "main.h"

/**
* elf_checker - check for elf.
* @e_ident: points to elf array.
*
* Description: checks the file to see if it's elf or not
*/
void elf_checker(unsigned char *e_ident)
{
	int ind;

	for (ind = 0; ind < 4; ind++)
	{
		if (e_ident[ind] != 127 && e_ident[ind] != 'E' &&
				e_ident[ind] != 'L' && e_ident[ind] != 'F')
		{
			dprintf(STDERR_FILENO, "Error: Not an ELF file\n");
			exit(98);
		}
	}
}
/**
* magic_pr - Prints magic
* @e_ident: points to ELF array.
*/
void magic_pr(unsigned char *e_ident)
{
	int ind

	printf("  Magic:   ");

	for (ind = 0; ind < EI_NIDENT; ind++)
	{
		printf("%02x", e_ident[ind]);

		if (ind == EI_NIDENT - 1)
			printf("\n");
		else
			printf(" ");
	}
}
/**
* class_pr - Prints class
* @e_ident: points to ELF array.
*/
void class_pr(unsigned char *e_ident)
{
	printf("  Class:                             ");

	if (e_ident[EI_CLASS] == ELFCLASS32)
	{
		printf("ELF32\n");
	}
	else if (e_ident[EI_CLASS] == ELFCLASS64)
	{
		printf("ELF64\n");
	}
	else if (e_ident[EI_CLASS] == ELFCLASSNONE)
	{
		printf("none\n");
	}
	else
	{
		printf("<unknown: %x>\n", e_ident[EI_CLASS]);
	}
}
/**
* data_pr - Prints data
* @e_ident: points to ELF array.
*/
void data_pr(unsigned char *e_ident)
{
	printf("  Data:                             ");

	if (e_ident[EI_DATA] == ELFDATA2MSB)
	{
		printf("2's complement, big endian\n");
	}
	else if (e_ident[EI_DATA] == ELFDATA2LSB)
	{
		printf("2's complement, little endian\n");
	}
	else if (e_ident[EI_DATA] == ELFDATANONE)
	{
		printf("none\n");
	}
	else
	{
		printf("<unknown: %x>\n", e_ident[EI_DATA]);
	}
}
/**
* main - Displays ELF Header
* @c: number of args.
* @v: pointer to args.
* Return: 0
*
* Description: Prints ELF Header
*/
int main(int __attribute__((__unused__)) c, char *v[])
{
	int openf, readf;
	Elf64_Ehdr *header;

	openf = open(v[1], O_RDONLY);
	if (openf == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read file %s\n", v[1]);
		exit(98);
	}

	header = malloc(sizeof(Elf64_Ehdr));
	if (header == NULL)
	{
		close_elf(openf);
		dprintf(STDERR_FILENO, "Error: Can't read file %s\n", v[1]);
		exit(98);
	}
	readf = read(openf, header, sizeof(Elf64_Ehdr));
	if (readf == -1)
	{
		free(header);
		close_elf(openf);
		dprintf(STDERR_FILENO, "Error: `%s`: No such file\n", v[1]);
		exit(98);
	}

	elf_checker(header->e_ident);
	printf("ELF Header:\n");
	magic_pr(header->e_ident);
	class_pr(header->e_ident);
	data_pr(header->e_ident);
	version_pr(header->e_ident);
	osabi_pr(header->e_ident);
	abi_pr(header->e_ident);
	type_pr(header->e_type, header->e_ident);
	entry_pr(header->e_entry, header->e_ident);

	free(header);
	close_elf(openf);
	return (0);
}
