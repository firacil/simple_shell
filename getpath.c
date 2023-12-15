#include "main.h"

char *fp_dir(char *path);
list_t *gp_dir(char *path);

/**
  * getpath - description
  * @command: a char type pointer
  * Return: pointer to
  */
char *getpath(char *command)
{
	char **path, *tempo;
	list_t *d, *head;
	struct stat st;

	path = _getenv("PATH");

	if (!path || !(*path))
		return (NULL);

	d = gp_dir(*path + 5);
	head = d;

	while (d)
	{
		tempo = malloc(_strlen(d->dir) + _strlen(command) + 2);
		if (!tempo)
			return (NULL);

		_strcpy(tempo, d->dir);
		_strcat(tempo, "/");
		_strcat(tempo, command);

		if (stat(tempo, &st) == 0)
		{
			free_list(head);
			return (tempo);
		}

		d = d->next;
		free(tempo);
	}
	free_list(head);

	return (NULL);
}

/**
 * fp_dir - copy path & replace leadingltrailing (:) with cwd.
 * @path: colon separated list of dir.
 * Return: pointer to copy.
 */

char *fp_dir(char *path)
{
	int i, len = 0;
	char *p_cp, *pwd;

	pwd = *(_getenv("PWD")) + 4;
	for (i = 0; path[i]; i++)
	{
		if (path[i] == ':')
		{
			if (path[i + 1] == ':' || i == 0 || path[i + 1] == '\0')
				len += _strlen(pwd) + 1;
			else
				len++;
		}
		else
			len++;
	}
	p_cp = malloc(sizeof(char) * (len + 1));
	if (!p_cp)
		return (NULL);
	p_cp[0] = '\0';
	for (i = 0; path[i]; i++)
	{
		if (path[i] == ':')
		{
			if (i == 0)
			{
				_strcat(p_cp, pwd);
				_strcat(p_cp, ":");
			}
			else if (path[i + 1] == ':' || path[i + 1] == '\0')
			{
				_strcat(p_cp, ":");
				_strcat(p_cp, pwd);
			}
			else
				_strcat(p_cp, ":");
		}
		else
		{
			_strncat(p_cp, &path[i], 1);
		}
	}
	return (p_cp);
}

/**
 * gp_dir - tokenize using fp_dir.
 * @path: colonseparated list of diectory.
 * Return: pointer to intaliazed LL.
 */

list_t *gp_dir(char *path)
{
	int index;
	char **d, *p_cp;
	list_t *head = NULL;

	p_cp = fp_dir(path);
	if (!p_cp)
		return (NULL);
	d = _strtok(p_cp, ":");
	free(p_cp);
	if (!d)
		return (NULL);

	for (index = 0; d[index]; index++)
	{
		if (n_end(&head, d[index]) == NULL)
		{
			free_list(head);
			free(d);
			return (NULL);
		}
	}

	free(d);
	return (head);
}
