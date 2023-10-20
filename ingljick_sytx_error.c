#include "main.h"

/**
 * rptd_cr - counts the repetitions of a char
 *
 * @ipb: ipb string
 * @i: index
 * Return: repetitions
 */
int rptd_cr(char *ipb, int i)
{
	if (*(ipb - 1) == *ipb)
		return (rptd_cr(ipb - 1, i + 1));

	return (i);
}

/**
 * ror_p_p - finds syntax errors
 *
 * @ipb: ipb string
 * @i: index
 * @last: last char read
 * Return: index of error. 0 when there are no
 * errors
 */
int ror_p_p(char *ipb, int i, char last)
{
	int ct;

	ct = 0;
	if (*ipb == '\0')
		return (0);

	if (*ipb == ' ' || *ipb == '\t')
		return (ror_p_p(ipb + 1, i + 1, last));

	if (*ipb == ';')
		if (last == '|' || last == '&' || last == ';')
			return (i);

	if (*ipb == '|')
	{
		if (last == ';' || last == '&')
			return (i);

		if (last == '|')
		{
			ct = rptd_cr(ipb, 0);
			if (ct == 0 || ct > 1)
				return (i);
		}
	}

	if (*ipb == '&')
	{
		if (last == ';' || last == '|')
			return (i);

		if (last == '&')
		{
			ct = rptd_cr(ipb, 0);
			if (ct == 0 || ct > 1)
				return (i);
		}
	}

	return (ror_p_p(ipb + 1, i + 1, *ipb));
}

/**
 * fi_crh - finds index of the first char
 *
 * @ipb: ipb string
 * @i: index
 * Return: 1 if there is an error. 0 in other case.
 */
int fi_crh(char *ipb, int *i)
{

	for (*i = 0; ipb[*i]; *i += 1)
	{
		if (ipb[*i] == ' ' || ipb[*i] == '\t')
			continue;

		if (ipb[*i] == ';' || ipb[*i] == '|' || ipb[*i] == '&')
			return (-1);

		break;
	}

	return (0);
}

/**
 * pt_ytx_ror - prints when a syntax error is found
 *
 * @datash: data structure
 * @ipb: ipb string
 * @i: index of the error
 * @bool: to control msg error
 * Return: no return
 */
void pt_ytx_ror(data_shell *datash, char *ipb, int i, int bool)
{
	char *msg, *msg2, *msg3, *error, *counter;
	int xlz;

	if (ipb[i] == ';')
	{
		if (bool == 0)
			msg = (ipb[i + 1] == ';' ? ";;" : ";");
		else
			msg = (ipb[i - 1] == ';' ? ";;" : ";");
	}

	if (ipb[i] == '|')
		msg = (ipb[i + 1] == '|' ? "||" : "|");

	if (ipb[i] == '&')
		msg = (ipb[i + 1] == '&' ? "&&" : "&");

	msg2 = ": Syntax error: \"";
	msg3 = "\" unexpected\n";
	counter = x_to(datash->counter);
	xlz = _xtln(datash->av[0]) + _xtln(counter);
	xlz += _xtln(msg) + _xtln(msg2) + _xtln(msg3) + 2;

	error = malloc(sizeof(char) * (xlz + 1));
	if (error == 0)
	{
		free(counter);
		return;
	}
	_sty(error, datash->av[0]);
	_sct(error, ": ");
	_sct(error, counter);
	_sct(error, msg2);
	_sct(error, msg);
	_sct(error, msg3);
	_sct(error, "\0");

	write(STDERR_FILENO, error, xlz);
	free(error);
	free(counter);
}

/**
 * ck_syx_ror - intermediate function to
 * find and print a syntax error
 *
 * @datash: data structure
 * @ipb: ipb string
 * Return: 1 if there is an error. 0 in other case
 */
int ck_syx_ror(data_shell *datash, char *ipb)
{
	int begin = 0;
	int f_char = 0;
	int i = 0;

	f_char = fi_crh(ipb, &begin);
	if (f_char == -1)
	{
		pt_ytx_ror(datash, ipb, begin, 0);
		return (1);
	}

	i = ror_p_p(ipb + begin, 0, *(ipb + begin));
	if (i != 0)
	{
		pt_ytx_ror(datash, ipb, begin + i, 1);
		return (1);
	}

	return (0);
}
