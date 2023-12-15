#ifndef MAIN_H
#define MAIN_H

#define READ_SIZE 1024
#define MAX_READ 100

#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <errno.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/wait.h>

#define END_OF_FILE -2
#define EXIT -3

/* global var */

char *name;
/* program name */
int hist;
/* history counter */

extern char **environ;

/**
 * struct alias_s - struct for my alias.
 * @name: name of the alias.
 * @value: value for alias.
 * @next: a pointer to another alias LL.
 */

typedef struct alias_s
{
	char *name;
	char *value;
	struct alias_s *next;
} alias_t;

/* global aliases to use */
alias_t *aliases;


/**
 * struct list_s - type define LL.
 * @dir: directory path.
 * @next: pointer to another LL
 */
typedef struct list_s
{
	char *dir;
	struct list_s *next;
} list_t;

/**
 * struct builtin_s - my vars defin builtin commands.
 * @name: name of builtin commands.
 * @f: function pointer to builtin commands function.
 */
typedef struct builtin_s
{
	char *name;
	int (*f)(char **argv, char **front);
} builtint_t;


/* Functions Prototype*/

void _puts(const char *s);
int _putchar(char c);
void *_realloc(void *ptr, unsigned int old, unsigned int new_size);
int (*get_builtin(char *command))(char **args, char **front);
char *getpath(char *command);
ssize_t _getline(char **lineptr, size_t *n, FILE *stream);
int _execve(char **av, char **first);
int _atoi(const char *s);
char *_itoa(int num);
char **_getenv(const char *var);
char **_strtok(char *line, char *delim);
list_t *n_end(list_t **head, char *dir);
void _free(char **s);

/* handlers */

void handle_line(char **line, ssize_t read);
void var_rep(char **args, int *eret);
char *get_args(char *line, int *eret);
int call_args(char **args, char **front, int *eret);
int run_args(char **args, char **front, int *eret);
int han_args(int *eret);
int check_args(char **args);
void free_args(char **args, char **front);
char **replace_alias(char **args);
int _error(char **args, int err);
list_t *gp_dir(char *path);
void free_alias(alias_t *head);

/* builtin */

int _myexit(char **args, char **front);
int _cd(char **args, char __attribute__((__unused__)) **front);
int _setenv(char **args, char __attribute__((__unused__)) **front);
int _env(char **args, char __attribute__((__unused__)) **front);

/* Strings */

int _strcmp(const char *s1, const char *s2);
size_t _strlen(const char *s);
char *_strdup(const char *src);
char *_strchar(const char *str, int character);
char *_strcpy(char *dest, const char *src);
char *_strcat(char *dest, const char *src);
int _strncmp(const char *s1, const char *s2, size_t n);
char *_strncat(char *dest, const char *src, size_t n);

/* handlers */
void han_s(int s);

/* LL help */

list_t *n_end(list_t **head, char *dir);
void free_list(list_t *head);

/* Builtin Helpers */

char **cpenv(void);
void f_env(void);

/* Error handling */

char *err_env(char **args);
char *err_1(char **args);
char *err_2ex(char **args);
char *err_2cd(char **args);
char *err_2syntax(char **args);
char *err_126(char **args);
char *err_127(char **args);

int _commands(char *fpath, int *eret);

#endif
