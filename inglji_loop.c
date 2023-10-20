#include "main.h"

/**
 * witt_cmt - deletes comments from the ipt
 *
 * @in: ipt string
 * Return: ipt without comments
 */
char *witt_cmt(char *in)
{
	int xix, up_to;

	up_to = 0;
	for (xix = 0; in[xix]; xix++)
	{
		if (in[xix] == '#')
		{
			if (xix == 0)
			{
				free(in);
				return (NULL);
			}

			if (in[xix - 1] == ' ' || in[xix - 1] == '\t' || in[xix - 1] == ';')
				up_to = xix;
		}
	}

	if (up_to != 0)
	{
		in = _rlc(in, xix, up_to + 1);
		in[up_to] = '\0';
	}

	return (in);
}

/**
 * shl_lp - Loop of shell
 * @datash: data relevant (av, ipt, args)
 *
 * Return: no return.
 */
void shl_lp(data_shell *datash)
{
	int lp, i_eof;
	char *ipt;

	lp = 1;
	while (lp == 1)
	{
		write(STDIN_FILENO, "^§^ ", 4);
		ipt = rxdx_ltx(&i_eof);
		if (i_eof != -1)
		{
			ipt = witt_cmt(ipt);
			if (ipt == NULL)
				continue;

			if (ck_syx_ror(datash, ipt) == 1)
			{
				datash->status = 2;
				free(ipt);
				continue;
			}
			ipt = rwp_vrw(ipt, datash);
			lp = xpt_csx(datash, ipt);
			datash->counter += 1;
			free(ipt);
		}
		else
		{
			lp = 0;
			free(ipt);
		}
	}
}
