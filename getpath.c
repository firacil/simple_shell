#include "main.h"

/**
  * is_excutable - description
  * @path: a char pointer parameter
  * Return: int
  */
int is_excutable(const char *path)
{
	return (access(path, X_OK) == 0);
}

/**
  * getpath - description
  * @command: a char type pointer
  * Return: pointer to
  */
char *getpath(char *command)
{
	char *valcp, *fpath, *token;
	int commlen, dirlen;
	struct stat buffer;
	char *value = getenv("PATH");

	if (value != NULL)
	{
		valcp = _strdup(value);
		commlen = _strlen(command);
		token = strtok(valcp, ":");

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
					free(fpath);
			}
			token = strtok(NULL, ":");
		}
		free(valcp);
		if (stat(command, &buffer) == 0)
			return (command);
		return (NULL);
	}
	return (NULL);
}
