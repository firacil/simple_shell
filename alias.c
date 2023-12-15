#include "main.h"

/**
 * replace_alias - replace any matching alias as arguments.
 * @args: pointer to the arguments (2D);
 * Return: pointer to the argumnet (@D).
 */

char **replace_alias(char **args)
{
	alias_t *temp;
	int i;
	char *new_val;

	if (_strcmp(args[0], "alias") == 0)
		return (args);
	for (i = 0; args[i]; i++)
	{
		temp = aliases;
		while (temp)
		{
			if (_strcmp(args[i], temp->name) == 0)
			{
				new_val = malloc(sizeof(char) * (_strlen(temp->value) + 1));
				if (!new_val)
				{
					free_args(args, args);
					return (NULL);
				}
				_strcpy(new_val, temp->value);
				free(args[i]);
				args[i] = new_val;
				i--;
				break;
			}
			temp = temp->next;
		}
	}

	return (args);
}
