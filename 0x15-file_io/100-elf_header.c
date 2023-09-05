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
