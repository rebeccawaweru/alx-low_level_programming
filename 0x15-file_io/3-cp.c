#include "main.h"
#include <stdarg.h>

/**
 * error - handles the errors in the main code
 * @code: exit code
 * @msg: error message
 * @f:file descriptor
 *
 * Return: 0
 */

int error(int code, char *msg, int f)
{
	switch (code)
	{
		case 97:
			dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
			exit(code);
		case 98:
			dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", msg);
			exit(code);
		case 99:
			dprintf(STDERR_FILENO, "Error: Can't write to %s\n", msg);
			exit(code);
		case 100:
			dprintf(STDERR_FILENO, "Error: Can't close f %d\n", f);
			exit(code);
		default:
			return (0);
	}
}

/**
 * main - creates copy of a file
 * @argc: argument counter
 * @argv: number of arguments
 *
 * Return: 0 if success
 */

int main(int argc, char *argv[])
{
	/*declarations*/
	int file_from, file_to;
	int read_state, write_state;
	int close_file_from, close_file_to;
	char buffer[1024];

	if (argc != 3) /*check number of arguments*/
		error(97, NULL, 0);
	file_from = open(argv[1], O_RDONLY);/*open file_from*/
	if (file_from < 0)/*check for error*/
		error(98, argv[1], 0);
	/* open file_to */
	file_to = open(argv[2], O_CREAT | O_TRUNC | O_WRONLY, 0664);
	if (file_to < 0)/*check for errir*/
		error(99, argv[2], 0);
	/* read file_from*/
	while ((read_state = read(file_from, buffer, 1024)) != 0)
	{
		if (read_state < 0) /*check for error*/
			error(98, argv[1], 0);
		write_state = write(file_to, buffer, read_state); /*write*/
		if (write_state < 0)
			error(99, argv[2], 0);
	}
	/* close file_from */
	close_file_from = close(file_from);
	if (close_file_from < 0)
		error(100, NULL, file_from);
	/* close file_to */
	close_file_to = close(file_to);
	if (close_file_to < 0)
		error(100, NULL, file_to);

	return (0);
}
