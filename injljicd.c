#include "main.h"

/**
 * cdx_dt - changes to the parent directory
 *
 * @dsh: data relevant (environ)
 *
 * Return: no return
 */
void cdx_dt(data_shell *dsh)
{
	char pwd[PATH_MAX];
	char *dir, *cp_pwd, *cp_strtok_pwd;

	getcwd(pwd, sizeof(pwd));
	cp_pwd = _sdp(pwd);
	xst_evx("OLDPWD", cp_pwd, dsh);
	dir = dsh->args[1];
	if (_rcp(".", dir) == 0)
	{
		xst_evx("PWD", cp_pwd, dsh);
		free(cp_pwd);
		return;
	}
	if (_rcp("/", cp_pwd) == 0)
	{
		free(cp_pwd);
		return;
	}
	cp_strtok_pwd = cp_pwd;
	v_trg(cp_strtok_pwd);
	cp_strtok_pwd = _ttk(cp_strtok_pwd, "/");
	if (cp_strtok_pwd != NULL)
	{
		cp_strtok_pwd = _ttk(NULL, "\0");

		if (cp_strtok_pwd != NULL)
			v_trg(cp_strtok_pwd);
	}
	if (cp_strtok_pwd != NULL)
	{
		chdir(cp_strtok_pwd);
		xst_evx("PWD", cp_strtok_pwd, dsh);
	}
	else
	{
		chdir("/");
		xst_evx("PWD", "/", dsh);
	}
	dsh->status = 0;
	free(cp_pwd);
}

/**
 * xcd_tx - changes to a directory given
 * by the user
 *
 * @dsh: data relevant (directories)
 * Return: no return
 */
void xcd_tx(data_shell *dsh)
{
	char pwd[PATH_MAX];
	char *dir, *cp_pwd, *cp_dir;

	getcwd(pwd, sizeof(pwd));

	dir = dsh->args[1];
	if (chdir(dir) == -1)
	{
		gxt_ror(dsh, 2);
		return;
	}

	cp_pwd = _sdp(pwd);
	xst_evx("OLDPWD", cp_pwd, dsh);

	cp_dir = _sdp(dir);
	xst_evx("PWD", cp_dir, dsh);

	free(cp_pwd);
	free(cp_dir);

	dsh->status = 0;

	chdir(dir);
}

/**
 * xcd_pvs - changes to the previous directory
 *
 * @dsh: data relevant (environ)
 * Return: no return
 */
void xcd_pvs(data_shell *dsh)
{
	char pwd[PATH_MAX];
	char *p_pwd, *p_oldpwd, *cp_pwd, *cp_oldpwd;

	getcwd(pwd, sizeof(pwd));
	cp_pwd = _sdp(pwd);

	p_oldpwd = _gxtx("OLDPWD", dsh->_environ);

	if (p_oldpwd == NULL)
		cp_oldpwd = cp_pwd;
	else
		cp_oldpwd = _sdp(p_oldpwd);

	xst_evx("OLDPWD", cp_pwd, dsh);

	if (chdir(cp_oldpwd) == -1)
		xst_evx("PWD", cp_pwd, dsh);
	else
		xst_evx("PWD", cp_oldpwd, dsh);

	p_pwd = _gxtx("PWD", dsh->_environ);

	write(STDOUT_FILENO, p_pwd, _xtln(p_pwd));
	write(STDOUT_FILENO, "\n", 1);

	free(cp_pwd);
	if (p_oldpwd)
		free(cp_oldpwd);

	dsh->status = 0;

	chdir(p_pwd);
}

/**
 * cdx_tx_hm - changes to home directory
 *
 * @dsh: data relevant (environ)
 * Return: no return
 */
void cdx_tx_hm(data_shell *dsh)
{
	char *p_pwd, *home;
	char pwd[PATH_MAX];

	getcwd(pwd, sizeof(pwd));
	p_pwd = _sdp(pwd);

	home = _gxtx("HOME", dsh->_environ);

	if (home == NULL)
	{
		xst_evx("OLDPWD", p_pwd, dsh);
		free(p_pwd);
		return;
	}

	if (chdir(home) == -1)
	{
		gxt_ror(dsh, 2);
		free(p_pwd);
		return;
	}

	xst_evx("OLDPWD", p_pwd, dsh);
	xst_evx("PWD", home, dsh);
	free(p_pwd);
	dsh->status = 0;
}
