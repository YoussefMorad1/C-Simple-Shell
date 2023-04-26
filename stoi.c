#include "string.h"
/** 
 * stoi - convert string to int
 * @s: string
 * Return: int
 */
int _stoi(char *s)
{
	int sz = _strlen(s), i, mul = 1, ans = 0;

	for (i = sz - 1; i >= 0; --i)
	{
		ans += (s[i] - '0') * mul;
		mul *= 10;
	}
	return ans;
}
