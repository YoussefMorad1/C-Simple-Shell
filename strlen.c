#include "string.h"
/**
 * _strlen - hi
 * Description - ss
 * @s : p
 * Return: hi
 */
int _strlen(char *s)
{
	int i = 0;

	for (; s[i] != '\0'; i++)
		;
	return (i);
}
