#include "main.h"

int main(int argc, char **argv)
{
	char *prompt = "simphell: ";
	char *input = NULL, **token_argv;
	const char *delim = " \n";
	int pid;
	(void)argc;
	(void)argv;

	while (1)
	{
		printf("%s", prompt);
		token_argv = tokenize(input, delim);
		if (token_argv[0] != NULL && strcmp(token_argv[0], "exit") == 0)
		{
			printf("Exiting Simphell\n");
			free(token_argv);
			break;
		}
		else if (token_argv[0] != NULL && strcmp(token_argv[0], "env") == 0)
		{
			env_cmd();
			free(token_argv);
			continue;
		}

		pid = fork();
		if (pid < 0)
		{
			perror("Wrong");
			return (-1);
		}

		else if (pid == 0)
			execmd(token_argv);
		else
			wait(NULL);

		free(token_argv);
	}
	free(input);
	return (0);
}
