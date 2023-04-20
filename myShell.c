#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/**
 * main - Spawn a shell using execve()
 *
 * @argc: Argument count
 * @argv: Arguent vector
 *
 * Return: 0 on SUCCESS
 */

int main(int argc, char *argv[])
{
	char *shell = "/bin/sh";
	char *args[] = {"/bin/sh", NULL};
	char *env[] = {NULL};

	if (execve(shell, args, env) == -1)
	{
		perror("Oops, something went wrong :/");
		exit(EXIT_FAILURE);
	}

	return (0);
}
