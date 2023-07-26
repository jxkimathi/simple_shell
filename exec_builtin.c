#include "shell.h"
#define DELIM " \n\t\r"

void free_tokens(char **args);

/**
 * tokenize - divides string into tokens
 * @str: string to tokenize
 * Return: pointer
 */

char **tokenize(char *str)
{
	char *token, **args /*str_cpy*/;
	int i = 0;

	args = malloc(sizeof(char *) * 1024);
	if (!args)
	{
		/*free(args)*/
		return (NULL);
	}
	token = strtok(str, DELIM);
	while (token)
	{
		args[i] = strdup(token);
		if (!args[i])
		{
			free_tokens(args);
			return (NULL);
		}
		token = strtok(NULL, DELIM);
		i++;
	}
	args[i] = NULL;
	return (args);
}

/**
 * free_tokens - frees the array of tokens
 * @args: array to be freed
 * Return: void
 */

void free_tokens(char **args)
{
	int i;

	if (args)
	{
		for (i = 0; args[i] != NULL; i++)
		{
			free(args[i]);
		}
		free(args);
		args = NULL;
	}
}
