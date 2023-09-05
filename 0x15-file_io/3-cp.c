#include "main.h"
/**
 * main - Copy file to another
 * @c: arguments count
 * @v: args double pointer
 * Return: 0
 */

int main(int c, char **v)
{
	char buffer[1024];
	int file1, file2, check;

	file1 = open(v[1], O_RDONLY);
	file2 = open(v[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);
	if (file1 == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", v[1]);
		exit(98);
	}
	if (file2 == -1)
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", v[2]), exit(99);
	if (c != 3)
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n"), exit(97);
	while (0 < (check = read(file1, buffer, 1024)))
	{
		if (check == -1)
		{
			dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", v[1]);
			exit(98);
		}
		check = write(file2, buffer, check);
		if (check == -1)
		{
			dprintf(STDERR_FILENO, "Error: Can't write to %s\n", v[2]);
			exit(99);
		}
	}
	if (check == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", v[1]);
		exit(98);
	}
	if (close(file1) == -1)
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", file1), exit(100);
	if (close(file2) == -1)
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", file2), exit(100);

	return (0);
}
