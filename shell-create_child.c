#include "shell.h"

/**
 * create_child - function creates sub process
 * @command: pointer to tokenised command
 * @name: pointer to name of shell
 * @env: pointer to environmental variables
 * @count: number of executed cycles
 * Return: Nothing
 */
void create_child(char **command, char *name, char **env, int count)
{
	int pid = 0;
	int status = 0;
	int wait_error = 0;

	pid = fork();
	if (pid < 0)
	{
		perror("Error: ");
		free_exit(command);
	}
	else if (pid == 0)
	{
		execute(command, name, env, count);
		free_dp(command);
	}
	else
	{
		wait_error = waitpid(pid, &status, 0);
		if (wait_error < 0)
		{
			free_exit(command);
		}
		free_dp(command);
	}
}
