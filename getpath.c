#include "main.h"

/**
 * Description here
 *
 */

int is_excutable(const char *path)
{
	return (access(path, X_OK) == 0);
}

/**
 * Description Here.
 */

char *getpath(char *command)
{
	char *valcp, *fpath;
	int commlen, dirlen;
	struct stat buffer;
	char *value = getenv("PATH");

	if (value != NULL)
	{
		valcp = strdup(value);
		commlen = strlen(command);
		char *token = strtok(valcp, ":");

		while (token != NULL)
		{
			if (is_excutable(token))
			{
				dirlen = strlen(token);

				fpath = malloc(commlen + dirlen + 2);
				strcpy(fpath, token);
				strcat(fpath, "/");
				strcat(fpath, command);
				strcat(fpath, "\0");

				if (stat(fpath, &buffer) == 0)
				{
					free(valcp);
					return (fpath);
				}
				else
				{
					free(fpath);
					token = strtok(NULL, ":");
				}
			}
		}
		free(valcp);
		return (NULL);
	}
	return (NULL);
}