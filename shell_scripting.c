#include "shell.h"

#define MAX 102400
/**
 * execute_script - executes commnads in a file
 * @filename: file containing the commands
 */
void execute_script(const char *filename, char **env)
{
	int fd, j, i;
	char buff[MAX], *line = NULL;
	ssize_t rd;

	if (access(filename, F_OK) != 0)
	{
		printf("./shell: %s: No such file or directory\n", filename);
		exit(EXIT_FAILURE);
	}
	if (access(filename, R_OK) != 0)
	{
		printf("./shell: %s: Permission denied\n", filename);
		exit(EXIT_FAILURE);
	}

	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		perror("open");
		exit(EXIT_FAILURE);
	}
	rd = read(fd, buff, sizeof(buff));
	if (rd == -1)
	{
		perror("read");
		close(fd);
		exit(EXIT_FAILURE);
	}
	i = 0;
	j = 0;
	while (i <= rd)
	{
		if (line == NULL)
		{
			line = malloc(64);
			if (line == NULL)
			{
				perror("malloc");
				close(fd);
				exit(EXIT_FAILURE);
			}
		}
		line[j++] = buff[i++];
		if (buff[i - 1] == '\n')
		{
			line[j] = '\0';
			execute_commands(line, env);
			free(line);
			line = NULL;
			j = 0;
		}

	}
	close(fd);
	exit(EXIT_SUCCESS);
}
