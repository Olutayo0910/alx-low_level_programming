#include "main.h"
#include <stdlib.h>

/**
 * argstostr - Concatenates all the arguments of a program.
 * @ac: Argument count.
 * @av: Argument vector.
 *
 * Return: Pointer to a new string, or NULL if it fails.
 */
char *argstostr(int ac, char **av)
{
	char *result;
	int total_length = 0;
	int i, j, index = 0;

	if (ac == 0 || av == NULL)
		return (NULL);

	for (i = 0; i < ac; i++)
	{
		if (av[i] == NULL)
			return (NULL);

		for (j = 0; av[i][j] != '\0'; j++)
			total_length++;
		total_length++;
	}

	result = malloc((total_length + 1) * sizeof(char));

	if (result == NULL)
	{
		free(result);
		return (NULL);
	}

	for (i = 0; i < ac; i++)
	{
		for (j = 0; av[i][j] != '\0'; j++)
		{
			result[index] = av[i][j];
			index++;
		}
		result[index] = '\n';
		index++;
	}

	result[index] = '\0';

	return (result);
}
