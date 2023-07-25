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
#include <stdarg.h>

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
int _strlen(char *s);
char *_strcpy(char *dest, char *src);
char *_strdup(char *str);
int _strncmp(const char *s1, const char *s2, size_t n);
int _strcmp(const char *s1, const char *s2);
char* _strcat(char *dest, const char *src);
char* _strtok(char* s, char* delm);
ssize_t _getline(char **line, size_t *len, FILE *file);

#endif /* SHELL_H */
