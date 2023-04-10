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
	char buffer[1024];
	/* total is total number of bytes noread and nowritten*/
	ssize_t noread, nowritten, total = 0;
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
	/* Read and write the contents of the file in chunks of */
	/* SIZE_OF_BUFFER bytes */
	while ((noread = read(f, buffer, sizeof(buffer))) > 0
	&& total < (ssize_t) letters)
	{
		/*write buffer contents to the standard output*/
		/*use STDOUT_FILENO - POSIX symbolic constant*/
		nowritten = write(STDOUT_FILENO, buffer, noread);
		/*check for error when writing standard output*/
		if (nowritten < 0)
			return (0);
		/*update the total letters read and printed*/
		total += nowritten;
	}
	/*check for errors in read opearation*/
	if (noread < 0)
		return (0);
	/*finally close the file)*/
	close(f);
	/*Return number of letters read and printed*/
	return (total);
}
