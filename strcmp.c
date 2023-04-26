#include "string.h"
/**
 * _strcmp - hi
 * @s : hi
 * @ss : yo
 * Return: hi
*/
int _strcmp(char *s, char *ss)
{
	int i = 0;

	for (i = 0; s[i] != '\0' && ss[i] != '\0'; ++i)
		if (s[i] != ss[i])
			return (s[i] - ss[i]);
	return (s[i] - ss[i]);
}
/**
 * _strncmp - hi
 * @s : hi
 * @ss : hi
 * @n : hi
 * Return: hi
 */
int _strncmp(char *s, char *ss, int n)
{
	int i = 0;

	for (i = 0; i < n && s[i] && ss[i]; ++i)
		if (s[i] != ss[i])
			return (s[i] - ss[i]);
	if (i == n)
		return (0);
	else
		return (s[i] - ss[i]);
}
