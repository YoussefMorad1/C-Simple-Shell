#include "header.h"
/**
 * find_file - search file in PATH
 * @file:  name of file
 * @path: path string with ':' sperated
 * Return: returns 1 or 0 or -1 if no memory
 */
int find_file(char *file, char *path)
{
	char **all_paths = split(path, ':');
	int i = 0;

	if (!all_paths)
		return (-1);
	if (is_file(file) && (file[0] == '/' || file[0] == '~' ||
				file[0] == '.' || file[0] == '#' || file[0] == '-'))
		return (1);
	while (all_paths[i])
	{
		char *cur_path = all_paths[i];
		char *full_path = malloc(strlen(cur_path) + strlen(file) + 5);
		char *slsh = "/\0";

		if (!cur_path || !full_path)
		{
			clean_strs(cur_path, full_path, 0);
			return (-1);
		}
		strcpy(full_path, cur_path);
		strcat(full_path, slsh);
		strcat(full_path, file);
		if (is_file(full_path))
			return (1);
		i++;
	}
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
	char **result = malloc(1), *tmp, *x;
	int i = 0;

	result[0] = 0;
	while (s[i])
	{
		while (s[i] == ' ' || s[i] == ch)
			i++;
		if (!s[i])
			break;
		tmp = malloc(1);

		tmp[0] = '\0';
		while (s[i] && s[i] != ch)
		{
			tmp = realloc(tmp, strlen(tmp) + 2);
			x = malloc(2);

			x[0] = s[i];
			x[1] = '\0';
			if (!tmp)
			{
				clean_strs(tmp, s, x);
				clean_args(result);
				return (0);
			}
			strcat(tmp, x);
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
