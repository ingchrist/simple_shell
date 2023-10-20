#include "main.h"

/**
 * sx_crx - checks ":" if is in the current directory.
 * @path: type char pointer char.
 * @xix: type int pointer of index.
 * Return: 1 if the path is searchable in the cd, 0 otherwise.
 */
int sx_crx(char *path, int *xix)
{
	if (path[*xix] == ':')
		return (1);

	while (path[*xix] != ':' && path[*xix])
	{
		*xix += 1;
	}

	if (path[*xix])
		*xix += 1;

	return (0);
}

/**
 * _which - locates a command
 *
 * @cmd: command name
 * @_environ: environment variable
 * Return: location of the command.
 */
char *_which(char *cmd, char **_environ)
{
	char *path, *ptr_path, *token_path, *dir;
	int len_dir, len_cmd, xix;
	struct stat st;

	path = _gxtx("PATH", _environ);
	if (path)
	{
		ptr_path = _sdp(path);
		len_cmd = _xtln(cmd);
		token_path = _ttk(ptr_path, ":");
		xix = 0;
		while (token_path != NULL)
		{
			if (sx_crx(path, &xix))
				if (stat(cmd, &st) == 0)
					return (cmd);
			len_dir = _xtln(token_path);
			dir = malloc(len_dir + len_cmd + 2);
			_sty(dir, token_path);
			_sct(dir, "/");
			_sct(dir, cmd);
			_sct(dir, "\0");
			if (stat(dir, &st) == 0)
			{
				free(ptr_path);
				return (dir);
			}
			free(dir);
			token_path = _ttk(NULL, ":");
		}
		free(ptr_path);
		if (stat(cmd, &st) == 0)
			return (cmd);
		return (NULL);
	}
	if (cmd[0] == '/')
		if (stat(cmd, &st) == 0)
			return (cmd);
	return (NULL);
}

/**
 * ixs_etbl - determines if is an executable
 *
 * @dth: data structure
 * Return: 0 if is not an executable, other number if it does
 */
int ixs_etbl(data_shell *dth)
{
	struct stat st;
	int xix;
	char *input;

	input = dth->args[0];
	for (xix = 0; input[xix]; xix++)
	{
		if (input[xix] == '.')
		{
			if (input[xix + 1] == '.')
				return (0);
			if (input[xix + 1] == '/')
				continue;
			else
				break;
		}
		else if (input[xix] == '/' && xix != 0)
		{
			if (input[xix + 1] == '.')
				continue;
			xix++;
			break;
		}
		else
			break;
	}
	if (xix == 0)
		return (0);

	if (stat(input + xix, &st) == 0)
	{
		return (xix);
	}
	gxt_ror(dth, 127);
	return (-1);
}

/**
 * ckx_ror_cd - verifies if user has permissions to access
 *
 * @dir: destination directory
 * @dth: data structure
 * Return: 1 if there is an error, 0 if not
 */
int ckx_ror_cd(char *dir, data_shell *dth)
{
	if (dir == NULL)
	{
		gxt_ror(dth, 127);
		return (1);
	}

	if (_rcp(dth->args[0], dir) != 0)
	{
		if (access(dir, X_OK) == -1)
		{
			gxt_ror(dth, 126);
			free(dir);
			return (1);
		}
		free(dir);
	}
	else
	{
		if (access(dth->args[0], X_OK) == -1)
		{
			gxt_ror(dth, 126);
			return (1);
		}
	}

	return (0);
}

/**
 * xdx_xc - executes command lines
 *
 * @dth: data relevant (args and input)
 * Return: 1 on success.
 */
int xdx_xc(data_shell *dth)
{
	pid_t pd;
	pid_t wpd;
	int state;
	int exec;
	char *dir;
	(void) wpd;

	exec = ixs_etbl(dth);
	if (exec == -1)
		return (1);
	if (exec == 0)
	{
		dir = _which(dth->args[0], dth->_environ);
		if (ckx_ror_cd(dir, dth) == 1)
			return (1);
	}

	pd = fork();
	if (pd == 0)
	{
		if (exec == 0)
			dir = _which(dth->args[0], dth->_environ);
		else
			dir = dth->args[0];
		execve(dir + exec, dth->args, dth->_environ);
	}
	else if (pd < 0)
	{
		perror(dth->av[0]);
		return (1);
	}
	else
	{
		do {
			wpd = waitpid(pd, &state, WUNTRACED);
		} while (!WIFEXITED(state) && !WIFSIGNALED(state));
	}

	dth->status = state / 256;
	return (1);
}
