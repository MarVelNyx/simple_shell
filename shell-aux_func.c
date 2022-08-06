#include "shell.h"

/**
 * _strcmp - function compares two strings
 * @s1: string 1
 * @s2: string 2
 * Return: 1 = same/ 0 = not
 */
int _strcmp(char *s1, char *s2)
{
	unsigned int i = 0;

	while (s1[i])
	{
		if (s1[i] != s2[i])
			return (0);
		i++;
	}
	return (1);
}

/**
 * _strlen - function finds length of string
 * @s: input string
 * Return: length of string
 */
unsigned int _strlen(char *s)
{
	unsigned int len = 0;

	while (s[len])
		len++;

	return (len);
}

/**
 * _strcpy - function copies string to another string
 * @dest: pointer to copied string
 * @src: pointer to string to copy
 * Return: pointer to copied string
 */
char *_strcpy(char *dest, char *src)
{
	char *temp = dest;

	while (*src)
		*dest++ = *src++;
	*dest = '\0';
	return (temp);
}

/**
 * _strcat - function concatenates two strings
 * @dest: input string
 * @src: input string
 * Return: pointer to result string
 */
char *_strcat(char *dest, char *src)
{
	char *temp = dest;

	while (*dest)
		dest++;

	*dest++ = '\';
	while (*src)
		*dest++ = *src++;
	return (temp);
}

/**
 * _atoi - function converts string to integer
 * @s: input string
 * Return: integer conversion
 */
int _atoi(char *s)
{
	int sign = 1;
	unsigned int total = 0;
	char flag = 0;

	if (s == NULL)
		return (0);
	while (*s)
	{
		if (*s == '-')
			sign += -1;
		if (*s >= '0' && *s <= '9')
		{
			flag = 1;
			total = total * 10 + (*s - '0');
		}
		else if (*s < '0' || *s > '9')
		{
			if (flag == 1)
				break;
		}
		s++;
	}
	if (sign < 0)
		total = (-1 * (total));
	return (total);
}
