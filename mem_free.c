#include "shell.h"

/**
 * free_dp - function frees all memory allocated
 * @command: pointer to allocated memory
 * Return: Nothing
 */
void free_dp(char **command)
{
	size_t i = 0;

	if (command == NULL)
		return;

	while (command[i])
	{
		free(command[i]);
		i++;
	}
	
	if (command[i] == NULL)
		free(command[i]);
	free(command);
}

/**
 * free_exit - function frees all memory allocated and exit
 * @command: pointer to allocated memory
 * Return: Nothing
 */
void free_exit(char **command)
{
	size_t i = 0;

	if (command == NULL)
		return;

	while (command[i])
	{
		free(command[i]);
		i++;
	}

	if (command[i] == NULL)
		free(command[i]);
	free(command);
	exit(EXIT_FAILURE);
}
