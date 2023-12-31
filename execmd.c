#include "main.h"

/**
 * execmd - executes a command
 * @argv: command to execute
 */

void execmd(char **argv)
{
	char *command = NULL, *real_command = NULL;
	int pid;

	if (argv)
	{
		command = argv[0];
		real_command = find_location(command);

		if (real_command == NULL)
			perror("Error");
		else
		{
			pid = fork();
			if (pid < 0)
				perror("Wrong");

			else if (pid == 0)
			{
				if (execve(real_command, argv, NULL) == -1)
					perror("Error");
			}

			else
				wait(NULL);
		}

		free(real_command);

	}
}
