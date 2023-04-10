#include "main.h"
/**
 * open_file - opens a file
 * main - calls all the functions
 * @flags: parameters used during system calls
 * @mode: interger that specifies the file permissions
 * @filename: name of the file
 * Return: 0
 */

int open_file(const char *filename, int flags, mode_t mode)
{
	int f = open(filename, flags, mode);

	return (f);
}

/**
 * copy_file - copy contents of a file
 * @f_from: file descriptor
 * @f_to: file descriptor
 * @dest_filename: file destination
 * @dest2_filename: file destination
 */
void copy_file(int f_from, int f_to,
const char *dest_filename, const char *dest2_filename)
{
	/*read in chunkcs of 1024 bytes at a time*/
	char buf[1024];
	ssize_t bytes_read;

	while ((bytes_read = read(f_from, buf, sizeof(buf))) > 0)
	{
		/*write the bytes read in the f_to*/
		ssize_t bytes_written = write(f_to, buf, bytes_read);
		/*check if error occurred when writing*/
		if (bytes_written != bytes_read)
		{
			dprintf(STDERR_FILENO, "Error: Can't write to %s\n", dest_filename);
			exit(99);
		}
	}

	/*check for read errors*/
	if (bytes_read < 0)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", dest2_filename);
		exit(98);
	}
}
/**
 * close_file -function to close a file
 * @fd: file descriptor
 */
void close_file(int fd)
{
	/*close the file*/
	close(fd);
	/*check for errors when closing*/
	if (fd < 0)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd);
		exit(100);
	}
}
/**
 * main - invokes all other functions
 * @argc: number of arguments
 * @argv: array of arguments
 *
 * Return: 0
 */
int main(int argc, char *argv[])
{
	int from, to;

	/*check for the number of arguments*/
	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from_file_to\n");
		exit(97);
	}
	/*invoke open_file() while passing arguments*/
	from = open_file(argv[1], O_RDONLY, 0);
	to = open_file(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0664);
	/*invoke copy_file() while passing arguments*/
	copy_file(from, to, argv[2], argv[1]);

	/*close the file descriptors*/
	close_file(from);
	close_file(to);
	return (0);
}
