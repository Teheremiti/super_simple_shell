#include <stdio.h>
#include <unistd.h>

/**
 * main - execve example
 *
 * Return: Always 0
 */

int main(int argc, char **argv)
{
	(void) argc;

	printf("Before execve\n");
	if (execve("./test", argv, NULL) == -1)
		perror("Error:");

	printf("After execve\n");
	return (0);
}
