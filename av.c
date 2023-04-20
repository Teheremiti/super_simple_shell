#include <stdio.h>

/**
 * main - argv
 *
 * @argc: Argument count
 * @argv: Argument vector
 *
 * Return: Always 0
 */

int main(int argc, char **argv)
{
	int i;
	(void) argc;

	for (i = 0; argv[i] != NULL; i++)
		printf("[%d] %s\n", i, argv[i]);

	return (0);
}
