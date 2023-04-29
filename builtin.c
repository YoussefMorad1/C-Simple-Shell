#include "shell.h"
/**
 * built_in - hi
 * @s : hi
 * @argv : hi
 * Return: intt
 */
int built_in(char *s, char **argv)
{
	if (!_strcmp(s, "env"))
		printenv(environ);
	else if (!_strcmp(s, "setenv"))
		_setenv(argv);
	else if (!_strcmp(s, "unsetenv"))
		_unsetenv(argv);
	else
		return (0);
	return (1);
}


/**
 * _setenv - hi
 * @argv: hi
 */
void _setenv(char **argv)
{
	char *key, *val, **ptr, *tmp;

	if (!argv[1] || !argv[2])
	{
		printers("failed to setenv\n");
		return;
	}
	key = argv[1], val = argv[2];
	tmp = malloc(_strlen(key) + _strlen(val) + 2);
	_strcpy(tmp, key);
	_strcat(tmp, "=");
	_strcat(tmp, val);
	for (ptr = environ; *ptr; ptr++)
	{
		if (!_strncmp(*ptr, key, _strlen(key)) && (*ptr)[_strlen(key)] == '=')
		{
			/*
			 * (*ptr) = tmp;
			 */
			_strcpy(*ptr, tmp);
			free(tmp);
			return;
		}
	}
	push(&environ, tmp);
	if (tmp)
		free(tmp);
}
/**
 * _unsetenv - hi
 * @argv: hi
 */
void _unsetenv(char **argv)
{
	char *key, **ptr, **tmp;

	if (!argv[1])
	{
		printers("failed to setenv\n");
		return;
	}
	key = argv[1];
	for (ptr = environ; *ptr; ptr++)
	{
		if (!_strncmp(*ptr, key, _strlen(key)) && (*ptr)[_strlen(key)] == '=')
		{
			printstr("helloworld\n");
			for (tmp = ptr + 1; *tmp; ptr++, tmp++)
				ptr = tmp;
			*ptr = 0;
			return;
		}
	}
}
