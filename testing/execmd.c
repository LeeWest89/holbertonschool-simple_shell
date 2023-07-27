#include "main.h"

void execmd(char **argv)
{
	char *command = NULL, *real_command = NULL;

	if (argv)
	{
		command = argv[0];
		real_command = find_location(command);

		if (execve(real_command, argv, NULL) == -1)
			perror("Error");
	}
}
