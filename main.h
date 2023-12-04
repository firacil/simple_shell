#ifndef MAIN_H
#define MAIN_H

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/wait.h>

extern char **environ;

/* Functions Prototype*/
int _putchar(char c);
int is_excutable(const char *path);
char *getpath(char *command);
int _execve(char **av);
int _token(char *line, char **tokens);
void currentenv(void);
void myexit(void);
char *situation(char **argv);
void cdd(char **argv);

#endif
