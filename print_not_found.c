#include "printf.h"
/**
 * print_not_found - hi
 * @nm: name
 * @cmd: cmd name
 */
void print_not_found(char *nm, char *cmd)
{
	printers(nm);
	printers(": 1: ");
	printers(cmd);
	printers(": not found\n");
}
