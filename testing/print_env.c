#include "main.h"

void print_env()
{
	size_t i;

	for (i = 0; environ[i] != NULL; i++)
		printf("%s\n", environ[i]);
}

void env_cmd()
{
	print_env();
}
