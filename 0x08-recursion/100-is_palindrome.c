#include "main.h"

/**
 * _strlen_recursion - Returns the length of a string.
 * @s: The string to calculate the length of.
 *
 * Return: The length of the string.
 */
int _strlen_recursion(char *s)
{
	if (*s == '\0')
		return (0);
	else
		return (1 + _strlen_recursion(s + 1));
}

/**
 * comparator - Compares each character of the string.
 * @s: The string to compare.
 * @start: The starting index of the comparison.
 * @end: The ending index of the comparison.
 *
 * Return: 1 if the substring is a palindrome, 0 otherwise.
 */
int comparator(char *s, int start, int end)
{
	if (*(s + start) == *(s + end))
	{
		if (start == end || start == end + 1)
			return (1);
		return (0 + comparator(s, start + 1, end - 1));
	}
	return (0);
}

/**
 * is_palindrome - Determines if a string is a palindrome.
 * @s: The string to check.
 *
 * Return: 1 if the string is a palindrome, 0 otherwise.
 */
int is_palindrome(char *s)
{
	if (*s == '\0')
		return (1);
	return (comparator(s, 0, _strlen_recursion(s) - 1));
}
