#include "main.h"

/**
 * read_textfile - function that reads text file and prints to POSIX
 * @letters: number of letters to be read and printed
 * @filename: the name of the file
 *
 * Return: letters if read and printed,
 * 0 if filename is NULL  or file not read or opened or write fails
 */

ssize_t read_textfile(const char *filename, size_t letters)
{
	int f; /*refers to the file descriptor*/
	/* maximum size of data we can read from a file in a single operation */
	char *buffer;
	 ssize_t noread, nowritten;
	/* first check if filename is NULL */
	if (filename == NULL)
		return (0);
	/* use open() to open the file */
	/* use O_RDONLY - to read the contents of the file */
	f = open(filename, O_RDONLY);
	/* f will have a negative value if the file has no contents*/
	/* or if an error ocurred when trying to open*/
	if (f < 0)
		return (0);

	buffer = malloc(sizeof(char) * letters + 1);
	if (buffer == NULL)
		return (0);
	/* Read and write the contents of the file  */
	noread = read(f, buffer, letters);
	if (noread < 0)
		return (0);

	buffer[letters + 1] = '\0';
	close(f);

	nowritten = write(STDOUT_FILENO, buffer, noread);
	/* check for errors when writing */
	if (nowritten < 0)
		return (0);

	free(buffer);

	return (noread);
}
