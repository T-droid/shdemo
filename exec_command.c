#include "shell.h"

#define MAX_BUFFER 1024
#define DELIMETERS " \t\r\n\a"

/**
 * execute_commands - executes commands
 * @line: string on the commandline
 */
void execute_commands(char *line, char **envp)
{
	char *buffer[MAX_BUFFER], *token, *buff;
	int pid, i = 0;
	int status;
	int last_exit_status = 0;

	token = strtok(line, DELIMETERS);
	while (token != NULL)
	{
		buffer[i++] = token;
		token = strtok(NULL, DELIMETERS);
	}
	buffer[i] = NULL;
	
	if (parser(buffer, envp, &last_exit_status) == 0)
		return;
	if (buffer[0][0] != '.' && buffer[0][0] != '/')
	{
		buff = findpath(buffer[0]);
		if (buff == NULL)
			perror("./shell");
	}
	else
		buff = buffer[0];
	if (buff == NULL)
	{
		last_exit_status = 126;
		return;
	}
	pid = fork();
	if (pid == -1)
		perror("fork");
	else if (pid == 0)
	{
		if (execve(buff, buffer, envp) == -1)
		{
			last_exit_status = 127;
			perror("./shell");
		}
	}
	else
	{
		wait(&status);
		if (WIFEXITED(status))
			last_exit_status = WEXITSTATUS(status);
		else if (WIFSIGNALED(status))
			last_exit_status = 126 + WTERMSIG(status);
		free(buff);
	}
	return;
}
