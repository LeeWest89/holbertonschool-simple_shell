#include "main.h"

/**
 * print_env - prints the environment
 */

void print_env()
{
	size_t i;

	for (i = 0; environ[i] != NULL; i++)
		printf("%s\n", environ[i]);
}

/**
 * env_cmd - prints the environment path
 */

void env_cmd()
{
	print_env();
}
