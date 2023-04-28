#include "printf.h"
/**
 * printenv - hi
 * @env: hi
 */
void printenv(char **env)
{
	char **s = env;

	for (; *s; s++) {
		printstr(*s);
		printstr("\n");
	}

}
