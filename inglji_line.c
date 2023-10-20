#include "main.h"

/**
 * xcx_lnx - finds builtins and commands
 *
 * @datash: data relevant (args)
 * Return: 1 on success.
 */
int xcx_lnx(data_shell *datash)
{
	int (*builtin)(data_shell *datash);

	if (datash->args[0] == NULL)
		return (1);

	builtin = get_builtin(datash->args[0]);

	if (builtin != NULL)
		return (builtin(datash));

	return (xdx_xc(datash));
}
