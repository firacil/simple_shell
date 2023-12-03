#ifndef MAIN_H
#define MAIN_H
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/wait.h>

/* Functions Prototype*/
int _putchar(char c);
int _execve(char **av);
int _token(char *line, char **tokens);

#endif
