#include "main.h"
/**
 * binary_to_uint - Converts a binary number to an unsigned int.
 * @b: A string of 0 and 1 chars.
 *
 * Return: The converted number, or 0 if there is an invalid character
 * or if b is NULL.
 */
unsigned int binary_to_uint(const char *b)
{
	unsigned int result;
	int length, base;

	if (!b)
		return (0);

	result = 0;

	for (length = 0; b[length] != '\0'; length++)
		;

	for (length--, base = 1; length >= 0; length--, base *= 2)
	{
		if (b[length] != '0' && b[length] != '1')
		{
			return (0);
		}

		if (b[length] & 1)
		{
			result += base;
		}
	}

	return (result);
}
