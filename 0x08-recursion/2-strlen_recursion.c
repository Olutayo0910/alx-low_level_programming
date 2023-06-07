#include main.h

/**
 * _strlen_recursion - returns the lenght of a string.
 * @s: string
 * Return: The lenght of a string
 */
int_strlen_recursion(char *s)
{
	if (*s == '\0')
	{
		return(0);
	}
	return 1 + _strlen_recursion(s + 1);
}
