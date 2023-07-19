#ifndef SHELL_H
#define SHELL_H
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <stddef.h>
#include <sys/wait.h>
#include <stdarg.h>
#include <stdlib.h>
#include <string.h>

char *findpath(char *str);
void myexit(char **args);
void environ(char **args, char **env);

#endif /* SHELL_H */
