#include "main.h"

/**
 * free_list - frees a list_e LL
 * @head: the head of list_e list.
 */

void free_list(list_t *head)
{
	list_t *next;

	while (head)
	{
		next = head->next;
		free(head->dir);
		free(head);
		head = next;
	}
}

/**
 * n_end - add a node to end of list_t LL.
 * @head: pointer to head of list_e list
 * @dir: directory path for the new node to contain.
 * Return: NULL or pointer to new node.
 */

list_t *n_end(list_t **head, char *dir)
{
	list_t *new_n = malloc(sizeof(list_t));
	list_t *last;

	if (!new_n)
		return (NULL);

	new_n->dir = dir;
	new_n->next = NULL;

	if (*head)
	{
		last = *head;
		while (last->next != NULL)
			last = last->next;
		last->next = new_n;
	}
	else
		*head = new_n;
	return (new_n);
}

/**
 * free_alias - free alias linked list.
 * @head: the head of the alias_t list.
 */

void free_alias(alias_t *head)
{
	alias_t *next;

	while (head)
	{
		next = head->next;
		free(head->name);
		free(head->value);
		free(head);
		head = next;
	}
}
