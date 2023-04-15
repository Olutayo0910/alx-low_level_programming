#include "main.h"

/**
 * read_textfile - reads a text file and prints it to the POSIX stdout
 * @filename: pointer to the file name
 * @letters: number of letters to read and print
 *
 * Return: actual number of letters it could read and print, 0 on failure
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	int fd;
	ssize_t n_bytes_read, n_bytes_written;
	char *buffer;

	if (filename == NULL)
		return (0);

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (0);

	buffer = malloc(sizeof(char) * letters);
	if (buffer == NULL)
	{
		close(fd);
		return (0);
	}

	n_bytes_read = read(fd, buffer, letters);
	close(fd);
	if (n_bytes_read == -1)
	{
		free(buffer);
		return (0);
	}

	n_bytes_written = write(STDOUT_FILENO, buffer, n_bytes_read);
	free(buffer);
	if (n_bytes_written != n_bytes_read)
		return (0);

	return (n_bytes_written);
}
