#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

char *_getenv(const char *name)
{
	extern char **environ;
	int i = 0;
	char *token;

	for (; environ[i] != NULL; i++)
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
