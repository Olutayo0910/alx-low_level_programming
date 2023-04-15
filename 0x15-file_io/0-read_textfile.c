#include "main.h"

/**
 * read_textfile - reads a text file and prints the letters
 * @filename: filename.
 * @letters: number of letters to print.
 *
 * Return: number of letters printed. If it fails, returns 0.
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
    int fd;
    ssize_t nread, nwritten;
    char *buf;

    if (!filename)
        return (0);

    fd = open(filename, O_RDONLY);

    if (fd == -1)
        return (0);

    buf = malloc(sizeof(char) * (letters + 1));
    if (!buf)
    {
        close(fd);
        return (0);
    }

    nread = read(fd, buf, letters);
    buf[nread] = '\0';

    nwritten = write(STDOUT_FILENO, buf, nread);

    close(fd);

    free(buf);

    return (nwritten);
}
