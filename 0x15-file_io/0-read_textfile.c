#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "main.h"

/**
 * read_textfile - reads a text file and then prints it.
 * @filename: const char type pointer to file to read
 * @letters: size_t type
 *
 * Return: readfile or 0
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	char *buf;
	ssize_t readfile;
	ssize_t writefile;
	ssize_t closefile;
	int x;

	buf = malloc(sizeof(char) * letters);
	if (filename == NULL)
	{
		free(buf);
		return (0);
	}
	if (buf == NULL)
	{
		return (0);
	}
	x = open(filename, O_RDONLY);
	readfile = read(x, buf, letters);
	writefile = write(STDOUT_FILENO, buf, readfile);

	if (readfile != writefile || readfile == -1 || writefile == -1 || x == -1)
	{
		free(buf);
		return (0);
	}

	free(buf);
	closefile = close(x);

	if (closefile == -1)
		return (0);

	return (readfile);
}
