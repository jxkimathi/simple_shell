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
	char *input_path, *input;
	pid_t pid;
	int status;

	if (!av[0])
		return (0);
	input = av[0];
	if (strcmp(input, "exit") == 0)
	{
		free_tokens(av);
		exit(0);
	}
	else if (strcmp(input, "env") == 0)
		shell_env();
	else
	{
		input_path = get_location(input);
		if (!input_path)
		{
			fprintf(stderr, "%s: 1: %s: not found\n", argv, input);
			return (0);
		}
		pid = fork();
		if (pid == -1)
			perror("Error");
		else if (pid == 0)
		{
			if (execve(input_path, av, NULL) == -1)
			{
				perror("Error: ");
				exit(0);
			}
		}
		else if (waitpid(pid, &status, 0) == -1)
			perror("Error: ");
		free(input_path);
	}
	return (0);
}

