#include "main.h"
#include <stdlib.h>

/**
 * str_concat - Concatenates two strings.
 * @s1: The first string.
 * @s2: The second string.
 *
 * Return: A pointer to the concatenated string, or NULL on failure.
 */
char *str_concat(char *s1, char *s2)
{
	char *newStr;
	int len1 = 0, len2 = 0, i, j;

	if (s1 == NULL)
		s1 = "";

	if (s2 == NULL)
		s2 = "";

	while (s1[len1] != '\0')
		len1++;

	while (s2[len2] != '\0')
		len2++;

	newStr = malloc(sizeof(char) * (len1 + len2 + 1));
	if (newStr == NULL)
	{
		free(newStr);
		return (NULL);
	}

	for (i = 0; i < len1; i++)
		newStr[i] = s1[i];

	for (j = 0; j < len2; j++, i++)
		newStr[i] = s2[j];

	return (newStr);
}
