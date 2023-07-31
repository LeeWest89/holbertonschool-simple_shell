#include "main.h"

int main(int argc, char **argv)
{
	char *prompt = "(simphell) $ ";
	char *input = NULL, *input_copy = NULL, *token;
	const char *delim = " \n";
	int i, token_count = 0;
	size_t n = 0;
	ssize_t c_read;
	(void)argc;

	while (1)
	{
		printf("%s", prompt);
		c_read = getline(&input, &n, stdin);

		if (c_read == -1)
		{
			printf("Exiting Simphell\n");
			return (-1);
		}

		input_copy = malloc(sizeof(char) * c_read);
		if (input_copy == NULL)
		{
			perror("tsh: memory allocation error");
			return (-1);
		}

		strcpy(input_copy, input);
		token = strtok(input_copy, delim);
		while (token != NULL)
		{
			token_count++;
			token = strtok(NULL, delim);
		}
		token_count++;

		argv = malloc(sizeof(char *) * token_count);
		token = strtok(input, delim);
		for (i = 0; token != NULL; i++)
		{
			argv[i] = malloc(sizeof(char) * strlen(token));
			strcpy(argv[i], token);
			/*printf(">> %s \n", argv[i]);*/
			token = strtok(NULL, delim);
		}
		argv[i] = NULL;

		execmd(argv);

		/*printf("%s", input);*/
		free(argv);
		free(input_copy);
		free(input);
	}
	return (0);
}
