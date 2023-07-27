#include "shell.h"

/**
 * shell_env - prints the current envirenment
 *
 * Return: void
 */

void shell_env(void)
{
	char **env = environ;

	while (*env)
	{
		printf("%s\n", *env);
		env++;
	}
}

/**
 * _execute - executes a command
 * @argv: name of the program
 * @av: the user input
 * Return: Nothing on success
 */

int _execute(char *argv, char **av)
{
	char *cmd_path, *cmd;
	pid_t pid;
	int status;

	if (!av[0])
		return (0);
	cmd = av[0];
	if (strcmp(cmd, "exit") == 0)
	{
		free_tokens(av);
		exit(0);
	}
	else if (strcmp(cmd, "env") == 0)
		shell_env();
	else
	{
		cmd_path = get_location(cmd);
		if (!cmd_path)
		{
			fprintf(stderr, "%s: 1: %s: not found\n", argv, cmd);
			return (0);
		}
		pid = fork();
		if (pid == -1)
			perror("Error");
		else if (pid == 0)
		{
			if (execve(cmd_path, av, NULL) == -1)
			{
				perror("Error: ");
				exit(0);
			}
		}
		else if (waitpid(pid, &status, 0) == -1)
			perror("Error: ");
		free(cmd_path);
	}
	return (0);
}

