#include "main.h"

/**
 * xcx_sh - changes current directory
 *
 * @datash: data relevant
 * Return: 1 on success
 */
int xcx_sh(data_shell *datash)
{
	char *dir;
	int shm, shm2, dsh;

	dir = datash->args[1];

	if (dir != NULL)
	{
		shm = _rcp("$HOME", dir);
		shm2 = _rcp("~", dir);
		dsh = _rcp("--", dir);
	}

	if (dir == NULL || !shm || !shm2 || !dsh)
	{
		cd_to_home(datash);
		return (1);
	}

	if (_rcp("-", dir) == 0)
	{
		cd_previous(datash);
		return (1);
	}

	if (_rcp(".", dir) == 0 || _rcp("..", dir) == 0)
	{
		cd_dot(datash);
		return (1);
	}

	cd_to(datash);

	return (1);
}
