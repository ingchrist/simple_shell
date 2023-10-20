#include "main.h"

/**
 * x_lp - Help information for the builtin hp.
 * Return: no return
 */
void x_lp(void)
{
	char *hp = "hp: hp [-dms] [pattern ...]\n";

	write(STDOUT_FILENO, hp, _xtln(hp));
	hp = "\tDisplay information about builtin commands.\n ";
	write(STDOUT_FILENO, hp, _xtln(hp));
	hp = "Displays brief summaries of builtin commands.\n";
	write(STDOUT_FILENO, hp, _xtln(hp));
}
/**
 * x_hp_ls - Help information for the builtin alias.
 * Return: no return
 */
void x_hp_ls(void)
{
	char *hp = "alias: alias [-p] [name[=value]...]\n";

	write(STDOUT_FILENO, hp, _xtln(hp));
	hp = "\tDefine or display aliases.\n ";
	write(STDOUT_FILENO, hp, _xtln(hp));
}
/**
 * u_p_c - Help information for the builtin alias.
 * Return: no return
 */
void u_p_c(void)
{
	char *hp = "cd: cd [-L|[-P [-e]] [-@]] [dir]\n";

	write(STDOUT_FILENO, hp, _xtln(hp));
	hp = "\tChange the shell working directory.\n ";
	write(STDOUT_FILENO, hp, _xtln(hp));
}
