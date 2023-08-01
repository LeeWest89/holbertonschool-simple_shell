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
		pid = fork();

		if (token_argv[0] != NULL && strcmp(token_argv[0], "exit") == 0)
		{
			printf("Exiting Simphell\n");
			free(token_argv);
			break;
		}

		if (pid != 0)
			wait(NULL);

		else if (pid == 0)
			execmd(token_argv);
		else
		{
			perror("Wrong");
			return (-1);
		}
		free(token_argv);
	}
	free(input);
	return (0);
}
