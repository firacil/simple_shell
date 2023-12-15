#include "main.h"

/**
  * _strchar - searches for first occurrences
  * @str: pointer to string to be searched
  * @character: character to be a located
  * Return: pointer to first occurrences, otherwise NULL
  */
char *_strchar(const char *str, int character)
{
	while (*str != '\0')
	{
		if (*str == (char)character)
		{
			return ((char *)str);
		}
		str++;
	}
	return (NULL);
}

/**
 * tok_len - locates delim index.
 * @str: sting to be searched.
 * @delim: delim.
 * Return: delim index.
 */

int tok_len(char *str, char *delim)
{
	int index = 0, len = 0;

	while (*(str + index) && *(str + index) != *delim)
	{
		len++;
		index++;
	}

	return (len);
}

/**
 * tok_count - count num of delim.
 * @str: string to be searched.
 * @delim: delimeter charchter.
 * Return: number of words containd within str.
 */

int tok_count(char *str, char *delim)
{
	int index, tokens = 0, len = 0;

	for (index = 0; *(str + index); index++)
		len++;

	for (index = 0; index < len; index++)
	{
		if (*(str + index) != *delim)
		{
			tokens++;
			index += tok_len(str + index, delim);
		}
	}
	return (tokens);
}

/**
 * _strtok - tokenize a string.
 * @line: string.
 * @delim: delimeter chachter to tokenize string.
 * Return: pointer to an array contatining the tokenized workds.
 */

char **_strtok(char *line, char *delim)
{
	char **ptr;
	int index = 0, tokens, t, lett, l;

	tokens = tok_count(line, delim);
	if (tokens == 0)
		return (NULL);

	ptr = malloc(sizeof(char *) * (tokens + 2));
	if (!ptr)
		return (NULL);

	for (t = 0; t < tokens; t++)
	{
		while (line[index] == *delim)
			index++;

		lett = tok_len(line + index, delim);

		ptr[t] = malloc(sizeof(char) * (lett + 1));
		if (!ptr[t])
		{
			for (index -= 1; index >= 0; index--)
				free(ptr[index]);
			free(ptr);
			return (NULL);
		}

		for (l = 0; l < lett; l++)
		{
			ptr[t][l] = line[index];
			index++;
		}
		ptr[t][l] = '\0';
	}
	ptr[t] = NULL;
	ptr[t + 1] = NULL;

	return (ptr);
}
