#include "shell.h"

/**
 * main - runs the shell.
 * @ac: number of inputed arguments.
 * @av: pointer to array of input arguments.
 * @env: pointer to array of envirnomental variables.
 * Return: EXIT_SUCCESS/ EXIT_FAILURE
 */
int main(int ac, char **av, char **env)
{
	char *buffer = NULL, **command = NULL;
	size_t buf_size = 0;
	ssize_t chars_read = 0;
	int count = 0;
	(void)ac;

	while (1)
	{
		count++;
		prompt();
		signal(SIGINT, handle);
		chars_read = getline(&buffer, &buf_size, stdin);
		if (chars_read == EOF)
			_EOF(buffer);
		else if (*buffer == '\n')
			free(buffer);
		else
		{
			buffer[_strlen(buffer) - 1] = '\0';
			command = tokening(buffer, "\0");
			free(buffer);
			if (_strcmp(command[0], "exit") != 0)
				shell_exit(command);
			else if (_strcmp(command[0], "cd") != 0)
				change_dir(command[1]);
			else
				create_child(command, av[0], env, count);
		}
		fflush(stdin);
		buffer = NULL, buf_size = 0;
	}
	if (chars_read == -1)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
