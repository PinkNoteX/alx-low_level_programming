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
	int len;
	int openf, writef;

	openf = open(filename, O_CREAT | O_TRUNC | O_WRONLY, 0600);
	if (filename == NULL)
		return (-1);
	if (openf == -1)
		return (-1);
	if (text_content == NULL)
		text_content = "";
	while (text_content[len] != '\0')
	{
		len++;
	}
	writef = write(openf, text_content, len);

	if (writef == -1)
		return (-1);
	close(openf);

	return (1);
}
