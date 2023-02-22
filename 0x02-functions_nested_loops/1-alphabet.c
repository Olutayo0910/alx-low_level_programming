#include "main.h"

/**
 * main - check th code
 *
 * Return: Always 0
 */
void print_alphabet(void)
{
	char ch;

	ch = 'a';

	while (ch <= 'z')
	{
		_putchar(ch);
		ch++;
	}

	_putchar("\n");

}
