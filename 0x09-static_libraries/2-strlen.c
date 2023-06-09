#include "main.h"

/**
 * _strlen - Returns the length of a string.
 * @s: Input string.
 *
 * Return: Length of the string.
 */
int _strlen(char *s)
{
	int count = 0;

	while (*(s + count) != '\0')
		count++;

	return (count);
}
