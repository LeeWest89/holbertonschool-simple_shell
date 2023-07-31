#include "main.h"

char *_getenv(const char *name)
{
	size_t i, nl;
	char *espos;

	for (i = 0; environ[i] != NULL; i++)
	{
		espos = strchr(environ[i], '=');
		if (espos == NULL || espos == environ[i])
			continue;

		nl = espos - environ[i];
		if (strncmp(environ[i], name, nl) == 0)
			return (espos + 1);
	}
	return (NULL);
}
