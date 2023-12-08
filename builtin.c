#include "main.h"

/**
 * myexit - a function exits the shell
 * Return: Nothing
 */
void myexit(void)
{
	exit(0);
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
		/* handle "cd -" to go back to prev directory */
		if (prevdir != NULL)
		{
			if (chdir(prevdir) != 0)
				perror("cd");
			/* swap current and previous directories in environment variable */
			_puts(prevdir);
			_puts("\n");
			setenv(PREV_DIR_ENV, curdir, 1);
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
