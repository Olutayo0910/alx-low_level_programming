#include "main.h"

/**
 * _puts - Prints a string, followed by a new line.
 * @str: Input string.
 *
 * Return: No return.
 */
void _puts(char *str)
{
	int count = 0;

	while (str[count] != '\0')
	{
		_putchar(str[count]);
		count++;
	}
	_putchar('\n');
}
