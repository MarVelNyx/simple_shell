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

/**
 * change_dir - function changes working directory
 * @path: new directory
 * Return: 1 = success/ 98 = fail
 */
int change_dir(const char *path)
{
	char *buf = NULL;
	size_t size = 1024;

	if (path == NULL)
		path = getcwd(buf, size);
	if (chdir(path) == -1)
	{
		perror(path);
		return (98);
	}
	return (1);
}
