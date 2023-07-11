#include "main.h"

/**
 * append_text_to_file - Appends text content to a file.
 * @filename: The name of the file.
 * @text_content: The text content to append.
 *
 * Return: 1 on success, -1 on failure.
 */
int append_text_to_file(const char *filename, char *text_content)
{
	int file_descriptor;
	int num_letters;
	int bytes_written;

	if (!filename)
		return (-1);

	file_descriptor = open(filename, O_WRONLY | O_APPEND);

	if (file_descriptor == -1)
		return (-1);

	if (text_content)
	{
		for (num_letters = 0; text_content[num_letters]; num_letters++)
			;

		bytes_written = write(file_descriptor, text_content, num_letters);

		if (bytes_written == -1)
			return (-1);
	}

	close(file_descriptor);

	return (1);
}
