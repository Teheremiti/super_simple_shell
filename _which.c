#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>

/**
 * _which - Look for files in the current PATH
 *
 * @filename: File to look for
 *
 * Return: (void)
 */

void _which(char *filename)
{
	char *path, *dir, file_path[1024];
	struct stat status;
	char *sep = "";

	if (filename[0] != '/')
		sep = "/";

	path = getenv("PATH");
	if (path == NULL)
	{
		fprintf(stderr, "PATH environment variable not found\n");
		exit(1);
	}

	dir = strtok(path, ":");
	while (dir)
	{
		int flag_stat, flag_access;

		sprintf(file_path, "%s%s%s", dir, sep, filename);
		flag_stat = stat(file_path, &status);
		flag_access = access(file_path, X_OK);
		if (flag_stat == 0 && flag_access == 0)
		{
			printf("%s\n", file_path);
			exit(0);
		}
		dir = strtok(NULL, ":");
	}

	printf("%s: command not found\n", filename);
	exit(2);
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
