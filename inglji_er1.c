#include "main.h"

/**
 * st_d - function that concatenates the message for cd ror
 *
 * @datash: data relevant (directory)
 * @mg: message to print
 * @ror: output message
 * @vr_sr: counter lines
 * Return: ror message
 */
char *st_d(data_shell *datash, char *mg, char *ror, char *vr_sr)
{
	char *lgl_fg;

	_sty(ror, datash->av[0]);
	_sct(ror, ": ");
	_sct(ror, vr_sr);
	_sct(ror, ": ");
	_sct(ror, datash->args[0]);
	_sct(ror, mg);
	if (datash->args[1][0] == '-')
	{
		lgl_fg = malloc(3);
		lgl_fg[0] = '-';
		lgl_fg[1] = datash->args[1][1];
		lgl_fg[2] = '\0';
		_sct(ror, lgl_fg);
		free(lgl_fg);
	}
	else
	{
		_sct(ror, datash->args[1]);
	}

	_sct(ror, "\n");
	_sct(ror, "\0");
	return (ror);
}

/**
 * ror_g_c - ror message for cd command in get_cd
 * @datash: data relevant (directory)
 * Return: Error message
 */
char *ror_g_c(data_shell *datash)
{
	int lgt, ln_d;
	char *ror, *vr_sr, *mg;

	vr_sr = x_to(datash->counter);
	if (datash->args[1][0] == '-')
	{
		mg = ": Illegal option ";
		ln_d = 2;
	}
	else
	{
		mg = ": can't cd to ";
		ln_d = _xtln(datash->args[1]);
	}

	lgt = _xtln(datash->av[0]) + _xtln(datash->args[0]);
	lgt += _xtln(vr_sr) + _xtln(mg) + ln_d + 5;
	ror = malloc(sizeof(char) * (lgt + 1));

	if (ror == 0)
	{
		free(vr_sr);
		return (NULL);
	}

	ror = st_d(datash, mg, ror, vr_sr);

	free(vr_sr);

	return (ror);
}

/**
 * ror_n_fd - generic ror message for command not found
 * @datash: data relevant (counter, arguments)
 * Return: Error message
 */
char *ror_n_fd(data_shell *datash)
{
	int lgt;
	char *ror;
	char *vr_sr;

	vr_sr = x_to(datash->counter);
	lgt = _xtln(datash->av[0]) + _xtln(vr_sr);
	lgt += _xtln(datash->args[0]) + 16;
	ror = malloc(sizeof(char) * (lgt + 1));
	if (ror == 0)
	{
		free(ror);
		free(vr_sr);
		return (NULL);
	}
	_sty(ror, datash->av[0]);
	_sct(ror, ": ");
	_sct(ror, vr_sr);
	_sct(ror, ": ");
	_sct(ror, datash->args[0]);
	_sct(ror, ": not found\n");
	_sct(ror, "\0");
	free(vr_sr);
	return (ror);
}

/**
 * ror_xt_sh - generic ror message for exit in get_exit
 * @datash: data relevant (counter, arguments)
 *
 * Return: Error message
 */
char *ror_xt_sh(data_shell *datash)
{
	int lgt;
	char *ror;
	char *vr_sr;

	vr_sr = x_to(datash->counter);
	lgt = _xtln(datash->av[0]) + _xtln(vr_sr);
	lgt += _xtln(datash->args[0]) + _xtln(datash->args[1]) + 23;
	ror = malloc(sizeof(char) * (lgt + 1));
	if (ror == 0)
	{
		free(vr_sr);
		return (NULL);
	}
	_sty(ror, datash->av[0]);
	_sct(ror, ": ");
	_sct(ror, vr_sr);
	_sct(ror, ": ");
	_sct(ror, datash->args[0]);
	_sct(ror, ": Illegal number: ");
	_sct(ror, datash->args[1]);
	_sct(ror, "\n\0");
	free(vr_sr);

	return (ror);
}
