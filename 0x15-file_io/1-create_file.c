#include "main.h"
/**
 * create_file - creates a file
 * @filename: name of file
 * @text_content: content of file
 *
 * Return: 1 on success -1 on fail
 */
int create_file(const char *filename, char *text_content)
{
	int len = 0;
	int openf, writef = 0;

	if (filename == NULL)
		return (-1);

	if (text_content != NULL)
	{
	while (text_content[len] != '\0')
	{
		len++;
	}
	}
	openf = open(filename, O_CREAT | O_RDWR | O_TRUNC, 0600);
	writef = write(openf, text_content, len);

	if (writef == -1 || openf == -1)
		return (-1);

	close(openf);

	return (1);
}
