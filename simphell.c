#include "main.h"

int main(int argc, char **argv)
{
	char *prompt = "(simphell) $ ";
	char *input;
	size_t n = 0;
	ssize_t c_read;
	(void)argc; (void)argv;

	while (1)
	{
		printf("%s", prompt);
		c_read = getline(&input, &n, stdin);

		if (c_read == -1)
		{
			printf("Exiting Simphell\n");
			return (-1);
		}
		printf("%s", input);
		free(input);
	}
	return (0);
}
