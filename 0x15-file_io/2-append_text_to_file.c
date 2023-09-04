#include "main.h"
/**
 * append_text_to_file - add text at the end of file.
 * @filename: name of file
 * @text_content: text to add
 *
 * Return: 1 on success -1 on fail
 */
int append_text_to_file(const char *filename, char *text_content)
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
	else
	{
		text_content = "";
	}
	openf = open(filename, O_WRONLY | O_APPEND);
	writef = write(openf, text_content, len);

	if (writef == -1 || openf == -1)
		return (-1);

	close(openf);

	return (1);
}
