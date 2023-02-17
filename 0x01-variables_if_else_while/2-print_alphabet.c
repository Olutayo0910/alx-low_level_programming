#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
 * main - Entry point
 *
 * Return: ALways 0 (Success)
 */
int main(void)
{
	char lowcase;

	for (lowcase = 'a'; lowcase <= 'z'; lowcase++)

		putchar(lowcase);
		putchar('\n');
	return (0);
}
