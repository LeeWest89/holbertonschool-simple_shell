#include "main.h"

char **tokenize(char *input, const char *delim)
{
	char **argv = NULL, *input_copy = NULL, *token;
	int i, token_count = 0;
	size_t n = 0;
	ssize_t c_read;

	c_read = getline(&input, &n, stdin);
	if (c_read == -1)
	{
		printf("Exiting Simphell\n");
		exit(-1);
	}
	input_copy = malloc(sizeof(char) * c_read);
	if (input_copy == NULL)
	{
		perror("tsh: memory allocation error");
		exit(-1);
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
		token = strtok(NULL, delim);
	}
	argv[i] = NULL;
	free(input_copy);
	return (argv);
}
