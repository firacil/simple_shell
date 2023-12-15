#include "main.h"

void free_args(char **args, char **front);
char *_getpid(void);
char *getenv_val(char *begin, int len);
void var_replace(char **args, int *eret);


/**
  * free_args - a function frees args.
  * @args: null terminated pinter .
  * @front: double pinter to begin of args.
  */

void free_args(char **args, char **front)
{
	size_t i;

	for (i = 0; args[i] || args[i + 1]; i++)
		free(args[i]);

	free(front);
}

/**
 * _getpid - get process id.
 * Return: current process id or NULL.
 */

char *_getpid(void)
{
	size_t i = 0;
	char *buffer;
	ssize_t file;

	file = open("/proc/self/stat", O_RDONLY);
	if (file == -1)
	{
		perror("can't read file");
		return (NULL);
	}
	buffer = malloc(120);
	if (!buffer)
	{
		close(file);
		return (NULL);
	}
	read(file, buffer, 120);
	while (buffer[i] != ' ')
		i++;
	buffer[i] = '\0';

	close(file);
	return (buffer);
}

/**
 * getenv_val - gets the value corresponding to env val.
 * @begin: the env var to search for.
 * @len: the length of env var to search for.
 * Return: empty or val of env variable.
 */

char *getenv_val(char *begin, int len)
{
	char **var_adr;
	char *rep = NULL, *temp, *var;

	var = malloc(len + 1);
	if (!var)
		return (NULL);
	var[0] = '\0';
	_strncat(var, begin, len);

	var_adr = _getenv(var);
	free(var);
	if (var_adr)
	{
		temp = *var_adr;
		while (*temp != '=')
			temp++;
		temp++;
		rep = malloc(_strlen(temp) + 1);
		if (rep)
			_strcpy(rep, temp);
	}

	return (rep);
}

/**
 * var_rep - handles variable replacement.
 * @line:  a double pointer contating the command and arguments.
 * @eret: pointer to the treturn value of last excuted command.
 */

void var_rep(char **line, int *eret)
{
	int j, k = 0, len;
	char *rep = NULL, *old = NULL, *newline;

	old = *line;
	for (j = 0; old[j]; j++)
	{
		if (old[j] == '$' && old[j + 1] &&
				old[j + 1] != ' ')
		{
			if (old[j + 1] == '$')
			{
				rep = _getpid();
				k = j + 2;
			}
			else if (old[j + 1] == '?')
			{
				rep = _itoa(*eret);
				k = j + 2;
			}
			else if (old[j + 1])
			{
				/* extract var name to search for */
				for (k = j + 1; old[k] &&
						old[k] != '$' &&
						old[k] != ' '; k++)
					;
				len = k - (j + 1);
				rep = getenv_val(&old[j + 1], len);
			}
			newline = malloc(j + _strlen(rep)
					+ _strlen(&old[k]) + 1);
			if (!line)
				return;
			newline[0] = '\0';
			_strncat(newline, old, j);
			if (rep)
			{
				_strcat(newline, rep);
				free(rep);
				rep = NULL;
			}
			_strcat(newline, &old[k]);
			free(old);
			*line = newline;
			old = newline;
			j = -1;
		}
	}
}
