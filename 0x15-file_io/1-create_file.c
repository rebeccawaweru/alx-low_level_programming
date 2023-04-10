#include "main.h"

/**
 * create_file - function that creates a file
 * @filename: name of the file
 * @text_content: NULL terminated string to add at end of the file
 *
 * Return: only return 1 on success otherwise -1
 */

int create_file(const char *filename, char *text_content)
{
	int f; /* file descriptor*/

	/*check if filename is NULL*/
	if (filename == NULL)
		return (-1);
	/*open() to open the file*/
	/*O_CREAT  create new file */
	/*O_TRUNC - all contents to be deleted if file exists*/
	/*O_WRONLY - open file in written only mode*/
	/*S_IRUSR, S_IWUSR- set permissions for read & write*/
	f = open(filename, O_CREAT | O_WRONLY | O_TRUNC, S_IRUSR | S_IWUSR);
	/*if error occurs during open return (-1)*/
	if (f < 0)
		return (-1);
	/*check if text_content is NULL*/
	if (text_content != NULL)
	{
		/*use write() to write contents of text_content*/
		/*strlen - get length of text_content string*/
		/*specifies number of bytes to write*/
		ssize_t written = write(f, text_content, strlen(text_content));
		/*check if error occured during writing*/
		if (written < 0)
			return (-1);
	}
	/*close the file*/
	close(f);
	return (1);
}
