#include "shell.h"
#define DELIM ":"

/**
 * get_location - searches and locates user input in the PATH.
 * @cmd: user input command to locate
 *
 * Return: If an error occurs or the command cannot be located - NULL.
 *         Otherwise - the full pathname of the command.
 */

char *get_location(const char *cmd)
{
	char *path, *token, *full_path, *path_env;
	int len;

	if (strchr(cmd, '/') != NULL)
	{
		if (access(cmd, X_OK) == 0)
			return (strdup(cmd));
		return (NULL);
	}
	path_env = getenv("PATH");
	if (!path_env)
	{
		return (NULL);
	}
	path = strdup(path_env);

	token = strtok(path, DELIM);

	while (token)
	{
		len = strlen(token) + strlen(cmd) + 2;
		full_path = malloc(sizeof(char) * len);
		if (!full_path)
		{
			free(path);
			return (NULL);
		}
		sprintf(full_path, "%s/%s", token, cmd);
		if (access(full_path, F_OK) == 0)
		{
			free(path);
			return (full_path);
		}
		free(full_path);
		token = strtok(NULL, DELIM);
	}
	free(path);
	return (NULL);
}

