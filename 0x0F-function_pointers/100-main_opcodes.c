#include <stdio.h>
#include <stdlib.h>

/**
 * main - Prints the opcodes of its own main function.
 * @argc: Number of arguments passed to the program.
 * @argv: Array of pointers to the arguments.
 *
 * Return: 0 on success.
 */
int main(int argc, char *argv[])
{
	char *opcodes = (char *)main;
	int i, num_bytes;

	if (argc != 2)
	{
		printf("Error\n");
		exit(1);
	}

	num_bytes = atoi(argv[1]);

	if (num_bytes < 0)
	{
		printf("Error\n");
		exit(2);
	}

	for (i = 0; i < num_bytes; i++)
	{
		printf("%02x", opcodes[i] & 0xFF);
		if (i != num_bytes - 1)
			printf(" ");
	}

	printf("\n");
	return (0);
}
