#include "main.h"

/**
 * cp_v_nm - compares env variables names
 * with the name passed.
 * @nenv: name of the environment variable
 * @name: name passed
 *
 * Return: 0 if are not equal. Another value if they are.
 */
int cp_v_nm(const char *nenv, const char *name)
{
	int xix;

	for (xix = 0; nenv[xix] != '='; xix++)
	{
		if (nenv[xix] != name[xix])
		{
			return (0);
		}
	}

	return (xix + 1);
}

/**
 * _gxtx - get an environment variable
 * @name: name of the environment variable
 * @_environ: environment variable
 *
 * Return: value of the environment variable if is found.
 * In other case, returns NULL.
 */
char *_gxtx(const char *name, char **_environ)
{
	char *ptr_env;
	int xix, xvx;

	/* Initialize ptr_env value */
	ptr_env = NULL;
	xvx = 0;
	/* Compare all environment variables */
	/* environ is declared in the header file */
	for (xix = 0; _environ[xix]; xix++)
	{
		/* If name and env are equal */
		xvx = cp_v_nm(_environ[xix], name);
		if (xvx)
		{
			ptr_env = _environ[xix];
			break;
		}
	}

	return (ptr_env + xvx);
}

/**
 * _evxz - prints the evironment variables
 *
 * @datash: data relevant.
 * Return: 1 on success.
 */
int _evxz(data_shell *datash)
{
	int xix, j;

	for (xix = 0; datash->_environ[xix]; xix++)
	{

		for (j = 0; datash->_environ[xix][j]; j++)
			;

		write(STDOUT_FILENO, datash->_environ[xix], j);
		write(STDOUT_FILENO, "\n", 1);
	}
	datash->status = 0;

	return (1);
}
