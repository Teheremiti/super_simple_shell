#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

/**
 * main - Excute the command `ls -l /tmp` in 5 different child processes
 *
 * Return: 0 on SUCCESS
 */

int main(void)
{
	char *sh = "/bin/ls";
	char *args[] = {"/bin/ls", "-l", "/tmp", NULL};
	char *env[] = {NULL};
	pid_t child_pid;
	int i;

	for (i = 0; i < 5; i++)
	{
		child_pid = fork();
		if (child_pid == -1)
		{
			perror("Error:");
			return (1);
		}

		if (child_pid == 0)
		{
			printf("Child process %d (PID %d)\n", i + 1, getpid());
			if (execve(sh, args, env) == -1)
			{
				printf("Oops\n");
				exit(EXIT_FAILURE);
			}
		}

		else
			wait(NULL);
	}

	printf("Hello, I am your father (PID %d)\n", getpid());
	return (0);
}
