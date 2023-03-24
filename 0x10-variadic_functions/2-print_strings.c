#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
/**
 * print_strings - prints string arguments with a separator
 *
 * @separator: - thing to print between strings
 * @n: - number of arguments
 *
 * Return: void
 */
void print_strings(const char *separator, const unsigned int n, ...)
{
	va_list args;
	char *str, *sep;
	unsigned int i;

	if (separator == NULL || *separator == 0){
		sep = ("");
	else
		sep = (char*) separator;

	va_start(args, n);

	if (n > 0){
		printf("%s", va_args(args, char*);
	
	for (i = 0; i < n; i++)
	{
		str = va_args(args, char*);

	if (str == NULL)
	{
		printf("(nil)");
	}
	else
	{
		printf("%s", sep, str);
		
		}
	}
	printf("\n");
	va_end(args);
	}

