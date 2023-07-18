#include "shell.h"

/**
 * main - entry point
 * @ac: argument count
 * @av: array of arguments
 * @envp: array of environmentall variables
 * Return: always 0
 */
int main(int ac, char **av, char **envp)
{
	char *line = NULL, *buffer[1024], *token, *buff;
	int pid, i, bt;
	size_t len = 0;

	(void)ac;
	(void)av;

	while (1)
	{
		i = 0;
		putchar('$');
		fflush(stdout);
		bt = getline(&line, &len, stdin);
		if (bt == -1)
		{
			perror("getline");
			exit(EXIT_FAILURE);
		}
		line[bt - 1] = '\0';

		token = strtok(line, " ");
		while (token != NULL)
		{
			buffer[i++] = token;
			token = strtok(NULL, " ");
		}

		buffer[i] = NULL;

		if (strcmp(buffer[0], "exit") == 0)
		{
			myexit(buffer);
			continue;
		}

		if (buffer[0][0] != '.' && buffer[0][0] != '/')
		{
			buff = findpath(buffer[0]);
			if (buff == NULL)
				perror("./shell");
		}
		else
			buff = buffer[0];

		if (buff == NULL)
			continue;
		pid = fork();

		if (pid == -1)
			perror("fork");
		else if (pid == 0)
		{
			if (execve(buff, buffer, envp) == -1)
			{
				perror("./shell");
			}
		}
		else
		{
			wait(NULL);
			free(buff);
		}
	}
	free(line);
	return (0);
}
