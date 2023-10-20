#include "main.h"

/**
 * rxdx_ltx - reads the ipt string.
 *
 * @i_eof: return value of getline function
 * Return: ipt string
 */
char *rxdx_ltx(int *i_eof)
{
	char *ipt = NULL;
	size_t bufsize = 0;

	*i_eof = getline(&ipt, &bufsize, stdin);

	return (ipt);
}
