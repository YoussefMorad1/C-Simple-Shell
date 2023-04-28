#include "shell.h"
/**
 * _getenv - get environment variable
 * @s: key of variable
 * Return: value of this given key
 */
char *_getenv(char *s)
{
	char **ptr = environ;

	for (; *ptr; ptr++)
	{
		if (!_strncmp(*ptr, s, _strlen(s)))
			return ((*ptr) + _strlen(s) + 1);
	}
	return (0);
}
/**
 * find_file - search file in PATH
 * @ptrFile:  name of file
 * @path: path string with ':' sperated
 * Return: returns 1 or 0 or -1 if no memory
 */
int find_file(char **ptrFile, char *path)
{
	char **all_paths = split(path, ':'), *file = *ptrFile,
	     *full_path, *slsh, *cur_path;
	int i = 0, tmp = errno;

	if (!all_paths)
		return (-1);
	if (is_file(file) && (file[0] == '/' || file[0] == '~' ||
				file[0] == '.' || file[0] == '#' || file[0] == '-')){
		clean_args(all_paths);
		errno = tmp;
		return (1);
	}
	while (all_paths[i])
	{
		cur_path = all_paths[i], slsh = "/\0";
		full_path = malloc(_strlen(cur_path) + _strlen(file) + 5);
		if (!cur_path || !full_path)
			clean_strs(cur_path, full_path, 0);
		if (!cur_path || !full_path)
			return (-1);
		_strcpy(full_path, cur_path);
		_strcat(full_path, slsh);
		_strcat(full_path, file);
		if (is_file(full_path) && file[0] != '/' && file[0] != '.')
		{
			free(file);
			(*ptrFile) = full_path;
			clean_args(all_paths);
			errno = tmp;
			return (1);
		}
		i++;
		free(full_path);
	}
	errno = tmp;
	clean_args(all_paths);
	return (0);
}

/**
 * is_file - is this file exits
 * @file: full path of file
 * Return: 1 or 0
 */
int is_file(char *file)
{
	struct stat st_file;

	return (stat(file, &st_file) == 0);
}
/**
 * split - split string with delimter ch
 * @s: string
 * @ch: delimter
 * Return: arr of strings
 */
char **split(char *s, char ch)
{
	char **result = malloc(sizeof(*result)), *tmp, *x, *tmp2;
	int i = 0;

	result[0] = 0;
	while (s[i])
	{
		while (s[i] == ' ' || s[i] == ch)
			i++;
		if (!s[i])
			break;
		tmp = malloc(1), tmp[0] = 0;
		while (s[i] && s[i] != ch)
		{
			tmp2 = malloc(_strlen(tmp) + 2);
			_strcpy(tmp2, tmp);
			free(tmp);
			tmp = tmp2;
			x = malloc(2);
			x[0] = s[i];
			x[1] = '\0';
			if (!tmp)
			{
				clean_strs(tmp, s, x);
				clean_args(result);
				return (0);
			}
			_strcat(tmp, x);
			i++;
			free(x);
		}
		if (!push(&result, tmp))
		{
			clean_strs(tmp, s, 0);
			clean_args(result);
			return (0);
		}
		free(tmp);
	}
	return (result);
}
