#include "shell.h"

/**
 * execute - function executes command
 * @command: pointer to tokenised command
 * @name: name of shell
 * @env: pointer to environmental variables
 * @count: number of executed cycles
 * Return: Noting
 */
void execute(char **command, char *name, char **env, int count)
{
	char **pathways = NULL, *full_path = NULL;
	struct stat st;
	unsigned int i = 0;

	if (_strcmp(command[0], "env") != 0)
		print_env(env);
	if (stat(command[0], &st) == 0)
	{
		if (execve(command[0], command, env) < 0)
		{
			perror(name);
			free_exit(command);
		}
	}
	else
	{
		pathways = _getPATH(env);
		while (pathways[i])
		{
			full_path = _strcat(pathways[i], command[0]);
			i++;
			if (stat(full_path, &st) == 0)
			{
				if (execve(full_path, command, env) < 0)
				{
					perror(name);
					free_dp(pathways);
					free_exit(command);
				}
				return;
			}
		}
		msg_error(name, count, command);
		free_dp(pathways);
	}
}

/**
 * print_env - function prints all environmental variables
 * @env: pointer to environmental variables
 * Return: Nothing
 */
void print_env(char **env)
{
	size_t i = 0, len = 0;

	while (env[i])
	{
		len = _strlen(env[i]);
		write(STDOUT_FILENO, env[i], len);
		write(STDOUT_FILENO, "\n", 1);
		i++;
	}
}

/**
 * _getPATH - function gets full value from env PATH
 * @env: pointer to environmental variables
 * Return: all tokenised pathways for commands
 */
char **_getPATH(char **env)
{
	char *pathvalue = NULL, **pathways = NULL;
	unsigned int i = 0;

	pathvalue = strtok(env[i], "=");
	while (env[i])
	{
		if (_strcmp(pathvalue, "PATH"))
		{
			pathvalue = strtok(NULL, "\n");
			pathways = tokening(pathvalue, ":");
			return (pathways);
		}
		i++;
		pathvalue = strtok(env[i], "=");
	}
	return (NULL);
}

/**
 * msg_error - function prints message: not found
 * @name: name of shell
 * @count: number of cycles
 * @command: tokenised command
 * Return: Nothing
 */
void msg_error(char *name, int count, char **command)
{
	char c;

	c = count + '0';
	write(STDOUT_FILENO, name, _strlen(name));
	write(STDOUT_FILENO, ":", 2);
	write(STDOUT_FILENO, &c, 1);
	write(STDOUT_FILENO, ":", 2);
	write(STDOUT_FILENO, command[0], _strlen(command[0]));
	write(STDOUT_FILENO, ": not found\n", 12);
}
