#include "main.h"
/**
 * read_textfile - Reads a text file and prints it to the POSIX standard output
 * @filename: The name of the file to read.
 * @letters: The number of letters to read and print.
 *
 * Return: The actual number of letters read and printed. Returns 0 on failure.
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	int file_desc;
	ssize_t num_read, num_written;
	char *buffer;

	if (!filename)
		return (0);

	file_desc = open(filename, O_RDONLY);
	if (file_desc == -1)
		return (0);

	buffer = malloc(sizeof(char) * letters);
	if (!buffer)
	{
		close(file_desc);
		return (0);
	}

	num_read = read(file_desc, buffer, letters);
	num_written = write(STDOUT_FILENO, buffer, num_read);

	close(file_desc);
	free(buffer);

	return (num_written);
}
