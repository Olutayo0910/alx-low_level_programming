#include "main.h"
#include <stdlib.h>

/**
 * ch_free_grid - Frees a 2-dimensional array of characters.
 * @grid: The grid to free.
 * @height: The height of the grid.
 *
 * Return: void.
 */
void ch_free_grid(char **grid, unsigned int height)
{
	if (grid != NULL && height != 0)
	{
		for (; height > 0; height--)
			free(grid[height - 1]);
		free(grid);
	}
}

/**
 * strtow - Splits a string into words.
 * @str: The string to split.
 *
 * Return: A pointer to an array of strings (words), or NULL if it fails.
 */
char **strtow(char *str)
{
	char **words;
	unsigned int count, height, i, j, index;

	if (str == NULL || *str == '\0')
		return (NULL);

	for (count = height = 0; str[count] != '\0'; count++)
	{
		if (str[count] != ' ' && (str[count + 1] == ' ' || str[count + 1] == '\0'))
			height++;
	}

	words = malloc((height + 1) * sizeof(char *));
	if (words == NULL || height == 0)
	{
		free(words);
		return (NULL);
	}

	for (i = index = 0; i < height; i++)
	{
		for (count = index; str[count] != '\0'; count++)
		{
			if (str[count] == ' ')
				index++;
			if (str[count] != ' ' && (str[count + 1] == ' ' || str[count + 1] == '\0'))
				break;
		}

		words[i] = malloc((count - index + 2) * sizeof(char));
		if (words[i] == NULL)
		{
			ch_free_grid(words, i);
			return (NULL);
		}

		for (j = 0; index <= count; index++, j++)
			words[i][j] = str[index];
		words[i][j] = '\0';
	}

	words[i] = NULL;
	return (words);
}
