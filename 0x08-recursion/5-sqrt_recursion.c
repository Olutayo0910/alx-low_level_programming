#include "main.h"

/**
 * _sqrt_recursion - Calculates the natural square root of a number.
 * @n: The number to calculate the square root of.
 *
 * Return: The natural square root of n,
 *         or -1 if n does not have a natural square root.
 */
int _sqrt_recursion(int n)
{
	if (n < 0)
		return (-1);

	return square_root_helper(n, 0);
}

/**
 * square_root_helper - Helper function to calculate the square root.
 * @n: The number to calculate the square root of.
 * @i: The current potential square root.
 *
 * Return: The square root of n if found,
 *         or -1 if n does not have a natural square root.
 */
int square_root_helper(int n, int i)
{
	if (i * i == n)
		return (i);

	if (i * i > n)
		return (-1);

	return (square_root_helper(n, i + 1));
}
