#include <stdio.h>
/**
 * main - prints the program name, and a new line.
 * @argc: counts command line arguments.
 * @argv: argument vector.
 * Return: 0 - success.
 */
int main(int argc __attribute__((unused)), char *argv[])
{
	printf("%s\n", argv[0]);
	return (0);
}

