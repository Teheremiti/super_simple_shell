#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void)
{
	extern char **environ;

	for (int i = 0; environ[i] != NULL; i++)
		printf("%s\n", environ[i]);

	return (0);
}
