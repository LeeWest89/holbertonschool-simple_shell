#include "main.h"

/**
 * * spacejam - determines if it is only space character
 * @input: input string
 *
 * Return: 0 if empty, -1 otherwise.
 */

int spacejam(char *input)
{
	int iter = 0;
	size_t numps = 0;

	if (input)
	{
		for (iter = 0; input[iter]; iter++)
		{
			if (input[iter] == '\n' ||
					input[iter] == '\r' ||
					input[iter] == ' ' ||
					input[iter] == '\t')
			{
				numps++;
			}
		}
	}
	return (numps == strlen(input) ? 0 : -1);
}
