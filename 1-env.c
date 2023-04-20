#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char **argv, char **env)
{
	extern char **environ;
	char ***address_env, ***address_environ;

	address_env = &env;
	address_environ = &environ;

	printf("&env: [%p]\n&environ: [%p]\n", address_env, address_environ);
	return (0);
}
