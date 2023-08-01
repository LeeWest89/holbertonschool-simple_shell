#include "main.h"

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

void free_arg(char **argv)
{
	int i;

	for (i = 0; argv[i]; i++)
		free(argv[i]);

	free(argv);
}
