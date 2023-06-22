#include "function_pointers.h"
#include <stdio.h>

/**
 * print_name - Prints a name.
 * @name: Pointer to the input name.
 * @f: Function pointer to a function.
 *
 * Description: This function prints a name
 * If 'name' or 'f' is NULL, the function does nothing.
 */
void print_name(char *name, void (*f)(char *))
{
	if (name && f)
		f(name);
}
