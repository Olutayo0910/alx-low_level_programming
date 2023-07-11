#include "main.h"
#include <stdio.h>

/**
 * error_file - checks if files can open.
 * @src_fd: source file descriptor.
 * @dest_fd: this the destination file descriptor.
 * @argv: arguments vector.
 *
 * Return: no return.
 */
void error_file(int src_fd, int dest_fd, char *argv[])
{
	if (src_fd == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
		exit(98);
	}
	if (dest_fd == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
		exit(99);
	}
}

/**
 * main - check the code.
 * @argc: number of arguments.
 * @argv: arguments vector.
 *
 * Return: Always 0.
 */
int main(int argc, char *argv[])
{
	int src_fd, dest_fd, err_close;
	ssize_t n_chars, n_wr;
	char buffer[1024];

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "%s\n", "Usage: cp file_from file_to");
		exit(97);
	}

	src_fd = open(argv[1], O_RDONLY);
	dest_fd = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC | O_APPEND, 0664);
	error_file(src_fd, dest_fd, argv);

	n_chars = 1024;
	while (n_chars == 1024)
	{
		n_chars = read(src_fd, buffer, 1024);
		if (n_chars == -1)
			error_file(-1, 0, argv);
		n_wr = write(dest_fd, buffer, n_chars);
		if (n_wr == -1)
			error_file(0, -1, argv);
	}

	err_close = close(src_fd);
	if (err_close == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", src_fd);
		exit(100);
	}

	err_close = close(dest_fd);
	if (err_close == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", src_fd);
		exit(100);
	}

	return (0);
}
