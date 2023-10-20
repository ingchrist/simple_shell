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
		cdx_tx_hm(datash);
		return (1);
	}

	if (_rcp("-", dir) == 0)
	{
		xcd_pvs(datash);
		return (1);
	}

	if (_rcp(".", dir) == 0 || _rcp("..", dir) == 0)
	{
		cdx_dt(datash);
		return (1);
	}

	xcd_tx(datash);

	return (1);
}
