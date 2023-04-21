#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "main.h"

/**
 * _getenv - Get the value of a environment variable if it exists
 *
 * @name: Variable to check
 *
 * Return: The value of the variable if it exists, otherwise NULL
 */

char *_getenv(const char *name)
{
	int i;
	char *token;

	for (i = 0; environ[i]; i++)
	{
		token = strtok(environ[i], "=");
		if (strcmp(token, name) == 0)
		{
			token = strtok(NULL, "\0");
			return (token);
		}
	}
	return (NULL);
}


/**
 * main - Own implementation of getenv()
 *
 * @argc: Argument vector
 * @argv: Argument count extern char **environ;
 *
 * Return: 0 on SUCCESS, otherwise 1
 */

int main(int argc, char **argv)
{
	char *env_var;

	if (argc != 2)
	{
		printf("Usage: %s <var name>\n", argv[0]);
		return (-1);
	}

	env_var = _getenv(argv[1]);
	printf("%s\n", env_var);
	return (0);
}
