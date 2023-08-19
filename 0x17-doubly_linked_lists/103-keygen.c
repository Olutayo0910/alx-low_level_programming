#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
 * f1 - Finds a character based on the length of the username
 *
 * @usrn: Username
 * @length: Length of the username
 * Return: A character based on the length
 */
int f1(char *usrn, int length)
{
	int c;
	int vch;
	unsigned int rand_num;

	c = *usrn;
	vch = 0;

	while (vch < length)
	{
		if (c < usrn[vch])
			c = usrn[vch];
		vch += 1;
	}

	srand(c ^ 14);
	rand_num = rand();

	return (rand_num & 63);
}

/**
 * f2 - Multiplies each character of the username
 *
 * @usrn: Username
 * @length: Length of the username
 * Return: Multiplied character
 */
int f2(char *usrn, int length)
{
	int c;
	int vch;

	c = vch = 0;

	while (vch < length)
	{
		c = c + usrn[vch] * usrn[vch];
		vch += 1;
	}

	return (((unsigned int)c ^ 239) & 63);
}

/**
 * f3 - Generates a random character
 *
 * @usrn: Username
 * Return: A random character
 */
int f3(char *usrn)
{
	int c;
	int vch;

	c = vch = 0;

	while (vch < *usrn)
	{
		c = rand();
		vch += 1;
	}

	return (((unsigned int)c ^ 229) & 63);
}

/**
 * main - Entry point
 *
 * @argc: Arguments count
 * @argv: Arguments vector
 * Return: Always 0
 */
int main(int argc, char **argv)
{
	char keygen[7];
	int length, c, vch;
	long alph[] = {
		0x3877445248432d41, 0x42394530534e6c37, 0x4d6e706762695432,
		0x74767a5835737956, 0x2b554c59634a474f, 0x71786636576a6d34,
		0x723161513346655a, 0x6b756f494b646850 };
	(void) argc;

	for (length = 0; argv[1][length]; length++)
		;
	/* ----------- f1 ----------- */
	keygen[0] = ((char *)alph)[(length ^ 59) & 63];
	/* ----------- f2 ----------- */
	c = vch = 0;
	while (vch < length)
	{
		c = c + argv[1][vch];
		vch = vch + 1;
	}
	keygen[1] = ((char *)alph)[(c ^ 79) & 63];
	/* ----------- f3 ----------- */
	c = 1;
	vch = 0;
	while (vch < length)
	{
		c = argv[1][vch] * c;
		vch = vch + 1;
	}
	keygen[2] = ((char *)alph)[(c ^ 85) & 63];
	/* ----------- f4 ----------- */
	keygen[3] = ((char *)alph)[f1(argv[1], length)];
	/* ----------- f5 ----------- */
	keygen[4] = ((char *)alph)[f2(argv[1], length)];
	/* ----------- f6 ----------- */
	keygen[5] = ((char *)alph)[f3(argv[1])];
	keygen[6] = '\0';
	for (c = 0; keygen[c]; c++)
		printf("%c", keygen[c]);
	return (0);
}
