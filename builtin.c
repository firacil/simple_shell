#include "main.h"

/**
 * Description
 */

void myexit(void)
{
	exit(0);
}

#define PREV_DIR_ENV "OLDPWD"
/**
 * description here
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
			{
				perror ("cd");
			}
			/* swap current and previous directories in environment variable */
			_puts(prevdir);
			_puts("\n");
			setenv(PREV_DIR_ENV, curdir, 1);
		}
		else
		{
			return;
		}
	}
	else 
	{
		if (chdir(arg[1]) != 0) /* change to specfied dir*/
		{
			perror("cd");
		}
		else
		{
			/* update nev var with current dir */
			setenv(PREV_DIR_ENV, curdir, 1);
		}
	}
	/* free space used for current directory*/
	free(curdir);
}

/**
 * descrption here
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

/*
 * Descrption here.
 */

#define MAX_PATH 4096

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
