#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>


/**
 * _which - Look for files in the current PATH
 *
 * @filename: File to look for
 *
 * Return: (void)
 */

void _which(char *filename)
{
	struct stat status;
	int flag = stat(filename, &status);

	if (flag > 0)
	{
		printf("%s: command not found\n", filename);
		exit(1);
	}

	else if (flag == -1)
	{
		perror("Error");
		exit(2);
	}

	else
	{
		printf("path_to_file\n");
		exit(0);
	}
}



/**
 * main - Own implementation of which command
 *
 * @argc: Argument count
 * @argv: Argument vector
 *
 * Return: 0 on SUCCESS, otherwise 1
 */

int main(int argc, char **argv)
{
	unsigned int i;

	if (argc < 2)
	{
		printf("Usage: %s filename ...\n", argv[0]);
		return (1);
	}

	for (i = 1; argv[i]; i++)
		_which(argv[i]);

	return (0);
}
