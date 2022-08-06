#include "shell.h"

/**
 * prompt - function prints prompt
 * Return: Nothing
 */
void prompt(void)
{
	if (isatty(STDIN_FILENO))
		write(STDOUT_FILENO, "($) ", 4);
}

/**
 * handle - function handle Ctrl + C signal
 * @signals: signal to handle
 * Return: Nothing
 */
void handle(int signals)
{
	(void)signals;
	write(STDOUT_FILENO, "\n($) ", 5);
}

/**
 * _EOF - function checks buffer is EOF
 * @buffer: pointer to input string
 * Return: Nothing
 */
void _EOF(char *buffer)
{
	if (buffer)
	{
		free(buffer);
		buffer = NULL;
	}

	if (isatty(STDIN_FILENO))
		write(STDOUT_FILENO, "\n", 1);
	free(buffer);
	exit(EXIT_SUCCESS);
}

/**
 * shell_exit - function exits shell
 * @command: pointer to tokenised command
 * Return: Nothing
 */
void shell_exit(char **command)
{
	int flag = 0;

	if (command[1] == NULL)
	{
		free_dp(command);
		exit(EXIT_SUCCESS);
	}

	flag = _atoi(command[1]);
	free_dp(command);
	if (flag >= 0 && flag <= 255)
		exit(flag);
	exit(255);
}
