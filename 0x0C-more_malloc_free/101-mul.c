#include "main.h"
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

/**
 * is_zero - determines if any number is zero
 * @args: argument vector.
 *
 * Return: no return.
 */
void is_zero(char *args[])
{
	int i, isNum1 = 1, isNum2 = 1;

	for (i = 0; args[1][i]; i++)
		if (args[1][i] != '0')
		{
			isNum1 = 0;
			break;
		}

	for (i = 0; args[2][i]; i++)
		if (args[2][i] != '0')
		{
			isNum2 = 0;
			break;
		}

	if (isNum1 == 1 || isNum2 == 1)
	{
		printf("0\n");
		exit(0);
	}
}

/**
 * initialize_array - set memory to zero in a new array
 * @arr: char array.
 * @len: length of the char array.
 *
 * Return: pointer of a char array.
 */
char *initialize_array(char *arr, int len)
{
	int i = 0;

	for (i = 0; i < len; i++)
		arr[i] = '0';
	arr[len] = '\0';
	return (arr);
}

/**
 * check_number - determines length of the number
 * and checks if the number is in base 10.
 * @args: arguments vector.
 * @n: row of the array.
 *
 * Return: length of the number.
 */
int check_number(char *args[], int n)
{
	int len;

	for (len = 0; args[n][len]; len++)
		if (!isdigit(args[n][len]))
		{
			printf("Error\n");
			exit(98);
		}

	return (len);
}

/**
 * main - Entry point.
 * Program that multiplies two positive numbers.
 * @argc: number of arguments.
 * @argv: arguments vector.
 *
 * Return: 0 - success.
 */
int main(int argc, char *argv[])
{
	int len1, len2, len_out, add, addl, i, j, k, ca;
	char *num_out;

	if (argc != 3)
		printf("Error\n"), exit(98);

	len1 = check_number(argv, 1);
	len2 = check_number(argv, 2);
	is_zero(argv);
	len_out = len1 + len2;
	num_out = malloc(len_out + 1);

	if (num_out == NULL)
		printf("Error\n"), exit(98);

	num_out = initialize_array(num_out, len_out);
	k = len_out - 1;
	i = len1 - 1;
	j = len2 - 1;
	ca = addl = 0;

	for (; k >= 0; k--, i--)
	{
		if (i < 0)
		{
			if (addl > 0)
			{
				add = (num_out[k] - '0') + addl;
				if (add > 9)
					num_out[k - 1] = (add / 10) + '0';
				num_out[k] = (add % 10) + '0';
			}
			i = len1 - 1;
			j--;
			addl = 0;
			ca++;
			k = len_out - (1 + ca);
		}

		if (j < 0)
		{
			if (num_out[0]
			break;
		}

		if (j >= 0)
		{
			add = ((argv[1][i] - '0') * (argv[2][j] - '0')) + (num_out[k] - '0') + addl;
			addl = add / 10;
			num_out[k] = (add % 10) + '0';
		}
	}

	printf("%s\n", num_out);
	free(num_out);
	return (0);
}
