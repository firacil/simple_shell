#include "main.h"

void sig_handler(int s);

/**
 * sig_handler - prints a new prompt upont a signal.
 * @s: signal.
 */

void sig_handler(int s)
{
	char *new_prompt = "\n$ ";

	(void)s;
	signal(SIGINT, sig_handler);
	write(STDIN_FILENO, new_prompt, 3);
}


/**
  * main - Entry point
  * @ac: argument count.
  * @argv: argument.
  * Return: exit status or success
  */

int main(int ac, char *argv[])
{
	int ret = 0, retn;
	int *eret = &retn;
	char *prompt = "$ ", *nline = "\n";

	name = argv[0];
	hist = 1;
	signal(SIGINT, sig_handler);
	*eret = 0;
	environ = cpenv();
	if (!environ)
		exit(-100);
	if (ac != 1)
	{
		ret = _commands(argv[1], eret);
		f_env();
		free_alias(aliases);
		return (*eret);
	}


	if (!isatty(STDIN_FILENO))
	{
		while (ret != END_OF_FILE && ret != EXIT)
			ret = han_args(eret);
		f_env();
		free_alias(aliases);
		return (*eret);
	}
	while (1)
	{
		write(STDOUT_FILENO, prompt, 2);
		ret = han_args(eret);
		if (ret == END_OF_FILE || ret == EXIT)
		{
			if (ret == END_OF_FILE)
				write(STDOUT_FILENO, nline, 1);
			f_env();
			free_alias(aliases);
			exit(*eret);
		}
	}

	f_env();
	free_alias(aliases);
	return (*eret);
}
