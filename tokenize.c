#include "main.h"

/**
 * tokenize - Function to create Tokens
 * @input: input to be tokenized
 * @delim: delimiter to be used by strtok
 * Return: Array of tokens
 */

char **tokenize(char *input, const char *delim)
{
	char **argv = NULL, *input_copy = NULL, *token;
	int i, token_count = 0;
	size_t n = 0;
	ssize_t c_read;

	c_read = getline(&input, &n, stdin);
	if (c_read == -1)
	{
		free(input);
		exit(0);
	}
	input_copy = malloc(sizeof(char) * c_read);
	if (input_copy == NULL)
	{
		perror("tsh: memory allocation error");
		exit(0);
	}
	strcpy(input_copy, input + 1);
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
		argv[i] = malloc(sizeof(char) * (strlen(token) + 1));
		strcpy(argv[i], token);
		token = strtok(NULL, delim);
	}
	argv[i] = NULL;
	free(input);
	free(input_copy);
	return (argv);
}
