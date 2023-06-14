#include <stdlib.h>

/**
 * argstostr - Concatenates all the arguments of the program.
 * @ac: The number of arguments.
 * @av: The array of arguments.
 * Return: Pointer to the concatenated string, or NULL on failure.
 */
char *argstostr(int ac, char **av)
{
	int i, j, k, len;
	char *str;
	int total_len = 0;

	if (ac == 0 || av == NULL)
		return (NULL);

	for (i = 0; i < ac; i++)
	{
		len = 0;
		while (av[i][len])
			len++;
		total_len += len;
	}
	total_len += ac - 1;
	str = malloc(sizeof(char) * (total_len + 1));
	if (str == NULL)
		return (NULL);

	k = 0;
	for (i = 0; i < ac; i++)
	{
		len = 0;
		while (av[i][len])
		{
			str[k] = av[i][len];
			k++;
			len++;
		}

		if (i != ac - 1)
		{
			str[k] = '\n';
			k++;
		}
	}

	str[k] = '\0';

	return (str);
}
