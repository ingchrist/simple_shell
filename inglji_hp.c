#include "main.h"

/**
 * ax_hp_v - Help information for the builtin env
 * Return: no return
 */
void ax_hp_v(void)
{
	char *hp = "env: env [option] [name=value] [command [args]]\n\t";

	write(STDOUT_FILENO, hp, _xtln(hp));
	hp = "Print the enviroment of the shell.\n";
	write(STDOUT_FILENO, hp, _xtln(hp));

}
/**
 * x_hp_sv - Help information for the builtin setenv
 * Return: no return
 */
void x_hp_sv(void)
{

	char *hp = "setenv: setenv (const char *name, const char *value,";

	write(STDOUT_FILENO, hp, _xtln(hp));
	hp = "int replace)\n\t";
	write(STDOUT_FILENO, hp, _xtln(hp));
	hp = "Add a new definition to the environment\n";
	write(STDOUT_FILENO, hp, _xtln(hp));
}
/**
 * a_hp_tv - Help information for the builtin unsetenv
 * Return: no return
 */
void a_hp_tv(void)
{
	char *hp = "unsetenv: unsetenv (const char *name)\n\t";

	write(STDOUT_FILENO, hp, _xtln(hp));
	hp = "Remove an entry completely from the environment\n";
	write(STDOUT_FILENO, hp, _xtln(hp));
}


/**
 * u_hp_gl - Entry point for hp information for the hp builtin
 * Return: no return
 */
void u_hp_gl(void)
{
	char *hp = "^-^ bash, version 1.0(1)-release\n";

	write(STDOUT_FILENO, hp, _xtln(hp));
	hp = "These commands are defined internally.Type 'hp' to see the list";
	write(STDOUT_FILENO, hp, _xtln(hp));
	hp = "Type 'hp name' to find out more about the function 'name'.\n\n ";
	write(STDOUT_FILENO, hp, _xtln(hp));
	hp = " alias: alias [name=['string']]\n cd: cd [-L|[-P [-e]] [-@]] ";
	write(STDOUT_FILENO, hp, _xtln(hp));
	hp = "[dir]\nexit: exit [n]\n  env: env [option] [name=value] [command ";
	write(STDOUT_FILENO, hp, _xtln(hp));
	hp = "[args]]\n  setenv: setenv [variable] [value]\n  unsetenv: ";
	write(STDOUT_FILENO, hp, _xtln(hp));
	hp = "unsetenv [variable]\n";
	write(STDOUT_FILENO, hp, _xtln(hp));
}
/**
 * x_hp_xt - Help information fot the builint exit
 * Return: no return
 */
void x_hp_xt(void)
{
	char *hp = "exit: exit [n]\n Exit shell.\n";

	write(STDOUT_FILENO, hp, _xtln(hp));
	hp = "Exits the shell with a status of N. If N is ommited, the exit";
	write(STDOUT_FILENO, hp, _xtln(hp));
	hp = "statusis that of the last command executed\n";
	write(STDOUT_FILENO, hp, _xtln(hp));
}
