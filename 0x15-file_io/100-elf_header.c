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
* version_pr - Prints version
* @e_ident: points to ELF array.
*/
void version_pr(unsigned char *e_ident)
{
	printf("  Version:                             %d", e_ident[EI_VERSION]);

	if (e_ident[EI_VERSION] == EV_CURRENT)
	{
		printf(" (current)\n");
	}
	else
	{
		printf("\n");
	}
}
/**
* abi_pr - Prints abi
* @e_ident: points to elf array.
*/
void abi_pr(unsigned char *e_ident)
{
	printf("  ABI Version:                       %d\n",
			e_ident[EI_ABIVERSION]);
}
/**
* osabi_pr - Prints osabi
* @e_ident: points to ELF array.
*/
void osabi_pr(unsigned char *e_ident)
{
	printf("  OS/ABI:                             ");

	if (e_ident[EI_OSABI] == ELFOSABI_STANDALONE)
		printf("Standalone App\n");
	else if (e_ident[EI_OSABI] == ELFOSABI_ARM)
		printf("ARM\n");
	else if (e_ident[EI_OSABI] == ELFOSABI_TRU64)
		printf("UNIX - TRU64\n");
	else if (e_ident[EI_OSABI] == ELFOSABI_FREEBSD)
		printf("UNIX - FreeBSD\n");
	else if (e_ident[EI_OSABI] == ELFOSABI_IRIX)
		printf("UNIX - IRIX\n");
	else if (e_ident[EI_OSABI] == ELFOSABI_SOLARIS)
		printf("UNIX - Solaris\n");
	else if (e_ident[EI_OSABI] == ELFOSABI_LINUX)
		printf("UNIX - Linux\n");
	else if (e_ident[EI_OSABI] == ELFOSABI_NETBSD)
		printf("UNIX - NetBSD\n");
	else if (e_ident[EI_OSABI] == ELFOSABI_HPUX)
		printf("UNIX - HP-UX\n");
	else if (e_ident[EI_OSABI] == ELFOSABI_NONE)
		printf("UNIX - System V\n");
	else
		printf("<unknown: %x>\n", e_ident[EI_OSABI]);
}
/**
* type_pr - Prints type
* @e_ident: points to ELF array.
*/
void type_pr(unsigned char *e_ident)
{
	if (e_ident[EI_DATA] == ELFDATA2MSB)
		e_type >>= 8;

	printf("  Type:                             ");

	if (e_type == ET_CORE)
	{
		printf("CORE (Core file)\n");
	}
	else if (e_type == ET_DYN)
	{
		printf("DYN (Shared object file)\n");
	}
	else if (e_type == ET_EXEC)
	{
		printf("EXEC (Executable file)\n");
	}
	else if (e_type == ET_REL)
	{
		printf("REL (Relocatable file)\n");
	}
	else if (e_type == ET_NONE)
	{
		printf("NONE (None)\n");
	}
	else
	{
		printf("<unknown: %x>\n", e_type);
	}
}
/**
 * entry_pr - Prints entry point
 * @e_entry: address of entry point
 * @e_ident: pointer to elf array
 */
void entry_pr(unsigned long int e_entry, unsigned char *e_ident)
{
	printf("  Entry point address:               ");

	if (e_ident[EI_DATA] == ELFDATA2MSB)
	{
		e_entry = ((e_entry << 8) & 0xFF00FF00) | ((e_entry >> 8) & 0xFF00FF);
		e_entry = (e_entry << 16) | (e_entry >> 16);
	}
	if (e_ident[EI_CLASS] == ELFCLASS32)
		printf("%#x\n", (unsigned int)e_entry);
	else
		printf("%#lx\n", e_entry);
}
/**
 * close_elf - closes elf file.
 * @elf: descriptor
 *
 * Description: error 98 if file can't be closed
 */
void close_elf(int elf)
{
	if (close(elf) == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", elf);
		exit(98);
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
