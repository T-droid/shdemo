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
#include <sys/types.h>

char *findpath(char *str);
void myexit(char **args);
int environ(char **args, char **env);
void env_helper(char *s1, char *s2, char **env);
int parser(char **str, char **env, int *status);
void printenv(void);
int changedir(char **args);
void varexpand(char **args, int *status);
void execute_script(const char *filename, char **env);
void execute_commands(char *line, char **envp);
void _printf(const char *format, ...);
void print_integer(int num);
int _putchar(char c);

#endif /* SHELL_H */
