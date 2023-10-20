#include "main.h"

/**
 * txt_sh - exits the shell
 *
 * @datash: data relevant (status and args)
 * Return: 0 on success.
 */
int txt_sh(data_shell *datash)
{
	unsigned int stt;
	int sx_dgx;
	int xr_lx;
	int bg_nb;

	if (datash->args[1] != NULL)
	{
		stt = _xti(datash->args[1]);
		sx_dgx = _sgt(datash->args[1]);
		xr_lx = _xtln(datash->args[1]);
		bg_nb = stt > (unsigned int)INT_MAX;
		if (!sx_dgx || xr_lx > 10 || bg_nb)
		{
			gxt_ror(datash, 2);
			datash->status = 2;
			return (1);
		}
		datash->status = (stt % 256);
	}
	return (0);
}
