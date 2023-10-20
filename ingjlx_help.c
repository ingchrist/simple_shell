#include "main.h"

/**
 * gx_hxp - function that retrieves help messages according builtin
 * @dsh: data structure (args and input)
 * Return: Return 0
*/
int gx_hxp(data_shell *dsh)
{

	if (dsh->args[1] == 0)
		u_hp_gl();
	else if (_rcp(dsh->args[1], "setenv") == 0)
		x_hp_sv();
	else if (_rcp(dsh->args[1], "env") == 0)
		ax_hp_v();
	else if (_rcp(dsh->args[1], "unsetenv") == 0)
		a_hp_tv();
	else if (_rcp(dsh->args[1], "help") == 0)
		x_lp();
	else if (_rcp(dsh->args[1], "exit") == 0)
		x_hp_xt();
	else if (_rcp(dsh->args[1], "cd") == 0)
		u_p_c();
	else if (_rcp(dsh->args[1], "alias") == 0)
		x_hp_ls();
	else
		write(STDERR_FILENO, dsh->args[0],
		      _xtln(dsh->args[0]));

	dsh->status = 0;
	return (1);
}
