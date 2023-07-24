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
	char *line = NULL;
	int bt;
	size_t len = 0;

	if (ac == 3)
	{
		if (strcmp(av[1], "simple_shell") == 0)
			execute_script(av[2], envp);
		else
		{
			printf("simple_shell [filename]\n");
			exit(EXIT_FAILURE);
		}
	}

	while (1)
	{
		putchar('$');
		putchar(' ');
		fflush(stdout);		

		bt = getline(&line, &len, stdin);
		if (bt == -1)
		{
			perror("getline");
			exit(EXIT_FAILURE);
		}
		if (line[0] == '\n')
			continue;

		line[bt - 1] = '\0';

		execute_commands(line, envp);
		/*token = strtok(line, DELIMETERS);
		while (token != NULL)
		{
			buffer[i++] = token;
			token = strtok(NULL, DELIMETERS);
		}

		buffer[i] = NULL;

		if (parser(buffer, envp, &last_exit_status) == 0)
			continue;

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
			continue;
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
		}*/
	}
	free(line);
	return (0);
}
