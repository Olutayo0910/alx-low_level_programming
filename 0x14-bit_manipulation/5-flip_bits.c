#include "main.h"
/**
 * flip_bits - Returns the number of bits needed to flip to convert
 *              one number to another.
 * @n: The first number.
 * @m: The second number.
 *
 * Return: The number of bits needed to flip.
 */
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	unsigned int bitCount;

	for (bitCount = 0; n || m; n >>= 1, m >>= 1)
	{
		if ((n & 1) != (m & 1))
			bitCount++;
	}

	return (bitCount);
}
