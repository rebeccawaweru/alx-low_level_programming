#include "lists.h"

/**
 * main - find passwords for crackme5
 * @argc: arguments
 * @argv: pointers to the arguments
 * Return: 0
 */
int main(int __attribute__((__unused__)) argc, char *argv[])
{
	int length = strlen(argv[1]), j, x;
	char passcode[7], *regex;

	regex = "A-CHRDw871NS0E9B2TibgpnMVys5XzvtOGJcYLU+4mjW6fxqZeF3Qa1rPhdKIouk";
	x = (length ^ 59) & 63;
	passcode[0] = regex[x];
	x = 0;
	for (j = 0; j < length; j++)
		x += argv[1][j];
	passcode[1] = regex[(x ^ 79) & 63];

	x = 1;
	for (j = 0; j < length; j++)
		x *= argv[1][j];
	passcode[2] = regex[(x ^ 85) & 63];

	x = 0;
	for (j = 0; j < length; j++)
	{
		if (argv[1][j] > x)
			x = argv[1][j];
	}
	srand(x ^ 14);
	passcode[3] = regex[rand() & 63];

	x = 0;
	for (j = 0; j < length; j++)
		x += (argv[1][j] * argv[1][j]);
	passcode[4] = regex[(x ^ 239) & 63];

	for (j = 0; j < argv[1][0]; j++)
		x = rand();
	passcode[5] = regex[(x ^ 229) & 63];
	printf("%s", passcode);
	return (0);
}
