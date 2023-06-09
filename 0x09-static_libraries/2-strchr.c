#include "main.h"

/**
 * _strchr - Locates a character in a string.
 * @s: String.
 * @c: Character.
 *
 * Return: Pointer to the first occurrence of the character c,
 *         or NULL if the character is not found.
 */
char *_strchr(char *s, char c)
{
	unsigned int i = 0;

	for (; s[i] != '\0'; i++)
	{
		if (s[i] == c)
			return (s + i);
	}

	if (s[i] == c)
		return (s + i);

	return ('\0');
}
