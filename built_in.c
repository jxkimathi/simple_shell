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
 * prompt - prints the prompt
 *
 * Return: void
 */

void prompt(void)
{
	if (isatty(STDIN_FILENO))
	{
		write(STDOUT_FILENO, "$ ", 2);
	}
}

/**
 * my_exit - executes a command that exits the shell
 * @argv: the arguements vector
 * @argc: the arguements count
 * Return: 0 on success
 */

int my_exit(int argc, char **argv)
{
	char *buf = NULL;
	int i;
	size_t len;
	ssize_t status;
	char **arg;

	while (1)
	{
		prompt();
		status = getline(&buf, &len, stdin);
		if (status == -1)
		{
			free(buf);
			exit(0);
		}
		arg = tokenize(buf);
		if (arg == NULL)
		{
			continue;
		}
		exec(argv[0], arg)
		if (execute_status != 0)

		free_tokens(arg);
		free(buf);
		buf = NULL;
		len = 0;
	}
	free_tokens(arg);
	return (0);
	argc++;
	argv[i] = "j";
}
