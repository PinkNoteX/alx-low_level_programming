#include <stdio.h>
#include <stdlib.h>
#include "main.h"

ssize_t read_textfile(const char *filename, size_t letters)
{
	char *buf;
	size_t readfile;
	size_t writefile;
	size_t closefile;
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
	readfile = (x, buf, letters);
	writefile = write(STDOUT_FILEND, buf, readfile);

	if(readfile != writefile || readfile == -1 || writefile == -1 || x == -1)
	{
		free (buf);
		return (0);
	}

	free (buf);
	closefile = close(x);

	if (closefile == -1)
		return (0);

	return (readfile);
}
