#include "main.h"

/**
 * append_text_to_file - function that appends text at end of file
 * @filename: name of the file
 * @text_content:  NULL terminated string to add at end of file
 *
 * Return: 1 on success otherwise -1
 */

int append_text_to_file(const char *filename, char *text_content)
{
	int f; /*the file descriptor*/

	/*check if filename is NULL*/
	if (filename == NULL)
		return (-1);
	/*open file with open()*/
	/*O_APPEND - used to append file*/
	/*O_WRONLY - open file in write mode*/
	f = open(filename, O_APPEND | O_WRONLY);
	/*check if file is opened successfully or is present*/
	if (f < 0)
		return (-1);
	/* append file if text_content is not NULL*/
	if (text_content != NULL)
	{
		/*strlen - length of text_content_string*/
		int new_file = write(f, text_content, strlen(text_content));
		/*check if append is successfully*/
		if (new_file < 0)
			return (-1);
		close(f);
		return (1);
	}
	/*close your file*/
	close(f);
	return (1);
}
