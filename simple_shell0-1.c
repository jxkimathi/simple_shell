#include "shell.h"

/**
 * main - A super simple shell that runs commands
 * @argc: Number of arguments
 * @argv: First argument name
 * @env: The environment
 *
 * Return: Always 0
 */

int main(int argc, char **argv, char **env)
{
	char *buffer = NULL;
	char *prompt = "$ ";
	pid_t pid;
	int status;
	struct stat statbuffer;
	ssize_t bytes;
	size_t n = 0;
	bool fr_pipe = false;

	while (1 && !fr_pipe)
	{
		if (isatty(STDIN_FILENO) == 0)
			fr_pipe = true;

		write (STDOUT_FILENO, prompt, 2);

		bytes = getline(&buffer, &n, stdin);

		if (bytes == -1)
		{
			perror("Error (from getline)");
			free(buffer);
			exit(EXIT_FAILURE);
		}

		if (buffer[bytes - 1] == '\n')
			buffer[bytes - 1] = '\0';

		pid = fork();

		if (pid == -1)
		{
			perror("Error (from fork)");
			exit(EXIT_FAILURE);
		}
		if (pid == 0)
			_execute(buffer, &statbuffer, env);

		if (waitpid(pid, &status, 0) == -1)
		{
			perror("Error (from wait)");
			exit(EXIT_FAILURE);
		}
	}

	free(buffer);
	return (0);
}

/**
 * _execute - Executes the program
 * @args: The number of arguments
 * @statbuffer: The structure to be checked
 * @envp: The environment variable
 *
 * Return: Nothing on success, otherwise return error
 */

int _execute(char *args, struct stat *statbuffer, char **envp)
{
	char **argv;

	argv = strtok(args, " ");

	if (!check_status(argv[0], statbuffer))
	{
		perror("Error (from file status)");
		exit(EXIT_FAILURE);
	}

	execve(argv[0], argv, envp);

	perror("Error (execve)");
	exit(EXIT_FAILURE);
}

/**
 * check_status - Checks the file status
 * @path: The path to check from
 * @statbuffer: The structure to be checked
 *
 * Return: false on success, otherwise true
 */

bool check_status(char *path, struct stat *statbuffer)
{
	int status_return;

	status_return = stat(path, statbuffer);

	if (status_return == 0)
		return (true);

	return (false);
}

/**
 * handle_error - Handles the errors
 * @pid: The process ID
 *
 * Return: Nothing
 */

void handle_error(pid_t pid)
{
	if (pid == -1)
	{
		printf("Error");
		exit(EXIT_FAILURE);
	}
}
