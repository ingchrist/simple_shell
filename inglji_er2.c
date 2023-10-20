#include "main.h"

/**
 * ror_v - ror message for env in get_env.
 * @datash: data relevant (counter, arguments)
 * Return: ror message.
 */
char *ror_v(data_shell *datash)
{
	int lgt;
	char *ror;
	char *r_tr;
	char *mg;

	r_tr = x_to(datash->counter);
	mg = ": Unable to add/remove from environment\n";
	lgt = _xtln(datash->av[0]) + _xtln(r_tr);
	lgt += _xtln(datash->args[0]) + _xtln(mg) + 4;
	ror = malloc(sizeof(char) * (lgt + 1));
	if (ror == 0)
	{
		free(ror);
		free(r_tr);
		return (NULL);
	}

	_sty(ror, datash->av[0]);
	_sct(ror, ": ");
	_sct(ror, r_tr);
	_sct(ror, ": ");
	_sct(ror, datash->args[0]);
	_sct(ror, mg);
	_sct(ror, "\0");
	free(r_tr);

	return (ror);
}
/**
 * *ror_pt_1 - ror message for path and failure denied permission.
 * @datash: data relevant (counter, arguments).
 *
 * Return: The ror string.
 */
char *ror_pt_1(data_shell *datash)
{
	int lgt;
	char *r_tr;
	char *ror;

	r_tr = x_to(datash->counter);
	lgt = _xtln(datash->av[0]) + _xtln(r_tr);
	lgt += _xtln(datash->args[0]) + 24;
	ror = malloc(sizeof(char) * (lgt + 1));
	if (ror == 0)
	{
		free(ror);
		free(r_tr);
		return (NULL);
	}
	_sty(ror, datash->av[0]);
	_sct(ror, ": ");
	_sct(ror, r_tr);
	_sct(ror, ": ");
	_sct(ror, datash->args[0]);
	_sct(ror, ": Permission denied\n");
	_sct(ror, "\0");
	free(r_tr);
	return (ror);
}
