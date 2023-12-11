#ifndef MAIN_H
#define MAIN_H

#define READ_SIZE 1024
#define MAX_READ 100

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/wait.h>

extern char **environ;

/* Functions Prototype*/

void _puts(const char *s);
int _putchar(char c);
int is_excutable(const char *path);
char *getpath(char *command);
ssize_t _getline(char **lineptr, size_t *n);
int _execve(char **av);
int _token(char *line, char **tokens);
int _atoi(const char *s);
char *_strtok(char *s, const char *delim);
void _free(char **s);

/* Builtins */

void currentenv(void);
int myexit(char **av);
void change_dir(char **arg);
int situation(char **argv);
char *get_currentdir(void);

/* Strings */
int _strcmp(const char *s1, const char *s2);
size_t _strlen(const char *s);
char *_strdup(const char *src);
char *_strcpy(const char *s);

#endif
