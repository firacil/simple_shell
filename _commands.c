#include "main.h"

int invalidopen(char *fpath);
int _commands(char *fpath, int *eret);

/**
 * invalidopen - if file not exist it will be printed.
 * @fpath: path to the file.
 * Return: 127
 */

int invalidopen(char *fpath)
{
	char *err, *hist_str;
	int len;

	hist_str = _itoa(hist);
	if (!hist_str)
		return (127);

	len = _strlen(name) + _strlen(hist_str) + _strlen(fpath) + 16;
	err = malloc(sizeof(char) * (len + 1));
	if (!err)
	{
		free(hist_str);
		return (127);
	}

	_strcpy(err, name);
	_strcat(err, ": ");
	_strcat(err, hist_str);
	_strcat(err, ": Can't open ");
	_strcat(err, fpath);
	_strcat(err, "\n");

	free(hist_str);
	write(STDERR_FILENO, err, len);
	free(err);
	return (127);
}

/**
 * _commands - takes a file and attempts to run command stored.
 * @fpath: path to the file.
 * @eret: return value of the last excuted command.
 * Return: file couldn't be opend -127/ value of last command.
 */

int _commands(char *fpath, int *eret)
{
	ssize_t file, bread, i;
	unsigned int line_size = 0;
	unsigned int old = 120;
	char *line, **args, **front;
	char buffer[120];
	int ret;

	hist = 0;
	file = open(fpath, O_RDONLY);
	if (file == -1)
	{
		*eret = invalidopen(fpath);
		return (*eret);
	}
	line = malloc(sizeof(char) * old);
	if (!line)
		return (-1);
	do {
		bread = read(file, buffer, 119);
		if (bread == 0 && line_size == 0)
			return (*eret);
		buffer[bread] = '\0';
		line_size += bread;
		line = _realloc(line, old, line_size);
		_strcat(line, buffer);
		old = line_size;
	} while (bread);
	for (i = 0; line[i] == '\n'; i++)
		line[i] = ' ';
	for (; i < line_size; i++)
	{
		if (line[i] == '\n')
		{
			line[i] = ';';
			for (i += 1; i < line_size && line[i] == '\n'; i++)
				line[i] = ' ';
		}
	}
	var_rep(&line, eret);
	handle_line(&line, line_size);
	args = _strtok(line, " ");
	free(line);
	if (!args)
		return (0);
	if (check_args(args) != 0)
	{
		*eret = 2;
		free_args(args, args);
		return (*eret);
	}
	front = args;

	for (i = 0; args[i]; i++)
	{
		if (_strncmp(args[i], ";", 1) == 0)
		{
			free(args[i]);
			args[i] = NULL;
			ret = call_args(args, front, eret);
			args = &args[++i];
			i = 0;
		}
	}
	ret = call_args(args, front, eret);

	free(front);
	return (ret);
}
