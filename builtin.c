#include "main.h"

/**
 * myexit - a function exits the shell
 * @av: argument passed
 * Return: status which helps to exit.
 */
int myexit(char **av)
{
	int ex_stat = EXIT_SUCCESS;

	if (av[1] != NULL)
	{
		ex_stat = _atoi(av[1]);
	}

	free(av);
	exit(ex_stat);
	return (ex_stat);
}

#define PREV_DIR_ENV "OLDPWD"
/**
 * change_dir - a function implement the builtin command cd
 * @arg: pointer to array of pointer
 * Return: Nothing
 */
void change_dir(char **arg)
{
	/* get current directory */
	char *curdir = get_currentdir();
	char *prevdir = getenv(PREV_DIR_ENV);
	char *newdir = NULL;

	if (curdir == NULL)
	{
		perror("get_currentdir");
		return;
	}

	if (arg[1] == NULL)
	{
		free(curdir);
		return;
	}
	else if (_strcmp(arg[1], "-") == 0)
	{
		if (prevdir != NULL)
		{
			newdir = prevdir;

			if (chdir(prevdir) != 0)
				perror("cd");
			/* swap current and previous directories in environment variable */
			else
				setenv(PREV_DIR_ENV, curdir, 1);
			free(newdir);
		}
		else
			return;
	}
	else
	{
		if (chdir(arg[1]) != 0) /* change to specfied dir*/
			perror("cd");
		else
			setenv(PREV_DIR_ENV, curdir, 1);
	}
	free(curdir);
}

/**
 * currentenv - a function mplement the built-in env command
 * Return: Nothign
 */
void currentenv(void)
{
	char **env = environ;

	while (*env != NULL)
	{
		_puts(*env);
		_puts("\n");
		env++;
	}
}
#define MAX_PATH 4096
/**
 * get_currentdir - a function check the current working directory
 *
 * Return: a char type pointer
 */
char *get_currentdir(void)
{
	/* allocating mem for buffer that store current working directory*/
	char *buf = malloc(MAX_PATH);

	/* checking if malloc is success*/
	if (buf != NULL)
	{
		/* using getcwd to get cwd */
		if (getcwd(buf, MAX_PATH) == NULL)
		{
			/*check for getcwd fail */
			perror("getcwd");
			free(buf);
			return (NULL);
		}
	}
	/* return the buf containing cur working dir */
	return (buf);
}
