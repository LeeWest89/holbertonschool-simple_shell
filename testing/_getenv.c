#include "main.h"

char **_getenv(const char *command)
{
	int i;

	for (i = 0; environ[i]; i++)
	{
		if (strcmp(command, environ[i]) == 0)
			return (&environ[i]);
	}
	return (NULL);
}
