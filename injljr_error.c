#include "main.h"

/**
 * gxt_ror - calls the ror according the builtin, syntax or permission
 * @datash: data structure that contains arguments
 * @eval: ror value
 * Return: ror
 */
int gxt_ror(data_shell *datash, int eval)
{
	char *ror;

	switch (eval)
	{
	case -1:
		ror = ror_v(datash);
		break;
	case 126:
		ror = ror_pt_1(datash);
		break;
	case 127:
		ror = ror_n_fd(datash);
		break;
	case 2:
		if (_rcp("exit", datash->args[0]) == 0)
			ror = ror_xt_sh(datash);
		else if (_rcp("cd", datash->args[0]) == 0)
			ror = ror_g_c(datash);
		break;
	}

	if (ror)
	{
		write(STDERR_FILENO, ror, _xtln(ror));
		free(ror);
	}

	datash->status = eval;
	return (eval);
}
