#include "main.h"

/**
 * get_builtin - builtin that pais the command in the arg
 * @xdax: command
 * Return: function pointer of the builtin command
 */
int (*get_builtin(char *xdax))(data_shell *)
{
	builtin_t builtin[] = {
		{ "env", _evxz },
		{ "exit", txt_sh },
		{ "setenv", _xvx },
		{ "unsetenv", _untvx },
		{ "cd", xcx_sh },
		{ "help", gx_hxp },
		{ NULL, NULL }
	};
	int xix;

	for (xix = 0; builtin[xix].name; xix++)
	{
		if (_rcp(builtin[xix].name, xdax) == 0)
			break;
	}

	return (builtin[xix].f);
}
