#include "main.h"

/**
 * cy_no - copies info to create
 * a new env or alias
 * @name: name (env or alias)
 * @value: value (env or alias)
 *
 * Return: new env or alias.
 */
char *cy_no(char *name, char *value)
{
	char *new;
	int len_name, len_value, len;

	len_name = _xtln(name);
	len_value = _xtln(value);
	len = len_name + len_value + 2;
	new = malloc(sizeof(char) * (len));
	_sty(new, name);
	_sct(new, "=");
	_sct(new, value);
	_sct(new, "\0");

	return (new);
}

/**
 * xst_evx - sets an environment variable
 *
 * @name: name of the environment variable
 * @value: value of the environment variable
 * @dth: data structure (environ)
 * Return: no return
 */
void xst_evx(char *name, char *value, data_shell *dth)
{
	int xix;
	char *var_env, *name_env;

	for (xix = 0; dth->_environ[xix]; xix++)
	{
		var_env = _sdp(dth->_environ[xix]);
		name_env = _ttk(var_env, "=");
		if (_rcp(name_env, name) == 0)
		{
			free(dth->_environ[xix]);
			dth->_environ[xix] = cy_no(name_env, value);
			free(var_env);
			return;
		}
		free(var_env);
	}

	dth->_environ = _reallocdp(dth->_environ, xix, sizeof(char *) * (xix + 2));
	dth->_environ[xix] = cy_no(name, value);
	dth->_environ[xix + 1] = NULL;
}

/**
 * _xvx - compares env variables names
 * with the name passed.
 * @dth: data relevant (env name and env value)
 *
 * Return: 1 on success.
 */
int _xvx(data_shell *dth)
{

	if (dth->args[1] == NULL || dth->args[2] == NULL)
	{
		gxt_ror(dth, -1);
		return (1);
	}

	xst_evx(dth->args[1], dth->args[2], dth);

	return (1);
}

/**
 * _untvx - deletes a environment variable
 *
 * @dth: data relevant (env name)
 *
 * Return: 1 on success.
 */
int _untvx(data_shell *dth)
{
	char **realloc_environ;
	char *var_env, *name_env;
	int xix, j, k;

	if (dth->args[1] == NULL)
	{
		gxt_ror(dth, -1);
		return (1);
	}
	k = -1;
	for (xix = 0; dth->_environ[xix]; xix++)
	{
		var_env = _sdp(dth->_environ[xix]);
		name_env = _ttk(var_env, "=");
		if (_rcp(name_env, dth->args[1]) == 0)
		{
			k = xix;
		}
		free(var_env);
	}
	if (k == -1)
	{
		gxt_ror(dth, -1);
		return (1);
	}
	realloc_environ = malloc(sizeof(char *) * (xix));
	for (xix = j = 0; dth->_environ[xix]; xix++)
	{
		if (xix != k)
		{
			realloc_environ[j] = dth->_environ[xix];
			j++;
		}
	}
	realloc_environ[j] = NULL;
	free(dth->_environ[k]);
	free(dth->_environ);
	dth->_environ = realloc_environ;
	return (1);
}
