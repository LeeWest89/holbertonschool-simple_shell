#include "main.h"

/**
 * main - entrty to function
 * @argc: Number of Arguments
 * @argv: Array of arguments
 * Return: Always returns 0
 */

int main(int argc, char **argv)
{
	char *prompt = "simphell: ";
	char *input = NULL, **token_argv;
	const char *delim = " \n";
	(void)argc;
	(void)argv;

	while (1)
	{
		printf("%s", prompt);
		token_argv = tokenize(input, delim);
		if (token_argv[0] != NULL && strcmp(token_argv[0], "exit") == 0)
		{
			printf("Exiting Simphell\n");
			free_arg(token_argv);
			break;
		}
		else if (token_argv[0] != NULL && strcmp(token_argv[0], "env") == 0)
		{
			env_cmd();
			free_arg(token_argv);
			continue;
		}
		execmd(token_argv);

		free_arg(token_argv);
	}
	free(input);
	return (0);
}

/**
 * free_arg - Function for freeing the array, argv
 * @argv: Array to be freed
 */

void free_arg(char **argv)
{
	int i;

	for (i = 0; argv[i]; i++)
		free(argv[i]);

	free(argv);
}
