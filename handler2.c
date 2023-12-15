#include "main.h"

void handle_line(char **line, ssize_t read);
ssize_t new_len(char *line);
void _andor(char *line, ssize_t *n_len);

/**
 * handle_line - handle input as wanted.
 * @line: pointer to input from stdin.
 * @read: length of line.
 * Return: None.
 */
void handle_line(char **line, ssize_t read)
{
	char *old, *new_line;
	char prev, cur, next;
	size_t i, j;
	ssize_t n_len;

	n_len = new_len(*line);
	if (n_len == read - 1)
		return;
	new_line = malloc(n_len + 1);
	if (!new_line)
		return;
	j = 0;
	old = *line;
	for (i = 0; old[i]; i++)
	{
		cur = old[i];
		next = old[i + 1];
		if (i != 0)
		{
			prev = old[i - 1];
			if (cur == ';')
			{
				if (next == ';' && prev != ' ' && prev != ';')
				{
					new_line[j++] = ' ';
					new_line[j++] = ';';
					continue;
				}
				else if (prev == ';' && next != ' ')
				{
					new_line[j++] = ';';
					new_line[j++] = ' ';
					continue;
				}
				if (prev != ' ')
					new_line[j++] = ' ';
				new_line[j++] = ';';
				if (next != ' ')
					new_line[j++] = ' ';
				continue;
			}
			else if (cur == '&')
			{
				if (next == '&' && prev != ' ')
					new_line[j++] = ' ';
				else if (prev == '&' && next != ' ')
				{
					new_line[j++] = '&';
					new_line[j++] = ' ';
					continue;
				}
			}
			else if (cur == '|')
			{
				if (next == '|' && prev != ' ')
					new_line[j++] = ' ';
				else if (prev == '|' && next != ' ')
				{
					new_line[j++] = '|';
					new_line[j++] = ' ';
					continue;
				}
			}
		}
		else if (cur == ';')
		{
			if (i != 0 && old[i - 1] != ' ')
				new_line[j++] = ' ';
			new_line[j++] = ';';
			if (next != ' ' && next != ';')
				new_line[j++] = ' ';
			continue;
		}
		new_line[j++] = old[i];
	}
	new_line[j] = '\0';

	free(*line);
	*line = new_line;
}

/**
 * new_len - gets new length of line partitoned
 *		by signs.
 * @line: line to be check.
 * Return: the new length of line.
 */

ssize_t new_len(char *line)
{
	size_t i;
	ssize_t n_len = 0;
	char cur, next;

	for (i = 0; line[i]; i++)
	{
		cur = line[i];
		next = line[i + 1];
		if (cur == '#')
		{
			if (i == 0 || line[i - 1] == ' ')
			{
				line[i] = '\0';
				break;
			}
		}
		else if (i != 0)
		{
			if (cur == ';')
			{
				if (next == ';' && line[i - 1] != ' ' && line[i - 1] != ';')
				{
					n_len += 2;
					continue;
				}
				else if (line[i - 1] == ';' && next != ' ')
				{
					n_len += 2;
					continue;
				}
				if (line[i - 1] != ' ')
					n_len++;
				if (next != ' ')
					n_len++;
			}
			else
				_andor(&line[i], &n_len);
		}
		else if (cur == ';')
		{
			if (i != 0 && line[i - 1] != ' ')
				n_len++;
			if (next != ' ' && next != ';')
				n_len++;
		}
		n_len++;
	}
	return (n_len);
}

/**
 * _andor - checker for logical opr && and ||.
 * @line: pointer to char to check line.
 * @n_len: point to new length.
 * Return: none.
 */

void _andor(char *line, ssize_t *n_len)
{
	char prev, cur, next;

	prev = *(line - 1);
	cur = *line;
	next = *(line + 1);

	if (cur == '&')
	{
		if (next == '&' && prev != ' ')
			(*n_len)++;
		else if (prev == '&' && next != ' ')
			(*n_len)++;
	}
	else if (cur == '|')
	{
		if (next == '|' && prev != ' ')
			(*n_len)++;
		else if (prev == '|' && next != ' ')
			(*n_len)++;
	}
}
