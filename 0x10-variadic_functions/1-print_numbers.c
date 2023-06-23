#include "variadic_functions.h"

/**
 * print_numbers - Prints numbers followed by a new line.
 * @separator: The string to be printed between numbers.
 * @n: The number of integers passed to the function.
 *
 * Return: void
 */
void print_numbers(const char *separator, const unsigned int n, ...)
{
	va_list args;
	unsigned int i;
	int num;

	va_start(args, n);

	if (separator != NULL)
	{
		for (i = 0; i < n; i++)
		{
			num = va_arg(args, int);
			printf("%d", num);

			if (i < n - 1)
				printf("%s", separator);
		}
		printf("\n");
	}

	va_end(args);
}
