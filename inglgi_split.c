#include "main.h"

/**
 * xsp_crx - swaps | and & for non-printed chars
 *
 * @input: input string
 * @bool: type of swap
 * Return: swapped string
 */
char *xsp_crx(char *input, int bool)
{
	int xix;

	if (bool == 0)
	{
		for (xix = 0; input[xix]; xix++)
		{
			if (input[xix] == '|')
			{
				if (input[xix + 1] != '|')
					input[xix] = 16;
				else
					xix++;
			}

			if (input[xix] == '&')
			{
				if (input[xix + 1] != '&')
					input[xix] = 12;
				else
					xix++;
			}
		}
	}
	else
	{
		for (xix = 0; input[xix]; xix++)
		{
			input[xix] = (input[xix] == 16 ? '|' : input[xix]);
			input[xix] = (input[xix] == 12 ? '&' : input[xix]);
		}
	}
	return (input);
}

/**
 * ad_xnds - add separators and command lines in the lists
 *
 * @head_s: head of separator list
 * @head_l: head of command lines list
 * @input: input string
 * Return: no return
 */
void ad_xnds(sep_list **head_s, line_list **head_l, char *input)
{
	int xix;
	char *line;

	input = xsp_crx(input, 0);

	for (xix = 0; input[xix]; xix++)
	{
		if (input[xix] == ';')
			a_sp_nd_d(head_s, input[xix]);

		if (input[xix] == '|' || input[xix] == '&')
		{
			a_sp_nd_d(head_s, input[xix]);
			xix++;
		}
	}

	line = _ttk(input, ";|&");
	do {
		line = xsp_crx(line, 1);
		d_li_de_d(head_l, line);
		line = _ttk(NULL, ";|&");
	} while (line != NULL);

}

/**
 * xgx_xtz - go to the next command line stored
 *
 * @list_s: separator list
 * @list_l: command line list
 * @datash: data structure
 * Return: no return
 */
void xgx_xtz(sep_list **list_s, line_list **list_l, data_shell *datash)
{
	int loop_sep;
	sep_list *ls_s;
	line_list *ls_l;

	loop_sep = 1;
	ls_s = *list_s;
	ls_l = *list_l;

	while (ls_s != NULL && loop_sep)
	{
		if (datash->status == 0)
		{
			if (ls_s->separator == '&' || ls_s->separator == ';')
				loop_sep = 0;
			if (ls_s->separator == '|')
				ls_l = ls_l->next, ls_s = ls_s->next;
		}
		else
		{
			if (ls_s->separator == '|' || ls_s->separator == ';')
				loop_sep = 0;
			if (ls_s->separator == '&')
				ls_l = ls_l->next, ls_s = ls_s->next;
		}
		if (ls_s != NULL && !loop_sep)
			ls_s = ls_s->next;
	}

	*list_s = ls_s;
	*list_l = ls_l;
}

/**
 * xpt_csx - splits command lines according to
 * the separators ;, | and &, and executes them
 *
 * @datash: data structure
 * @input: input string
 * Return: 0 to exit, 1 to continue
 */
int xpt_csx(data_shell *datash, char *input)
{

	sep_list *head_s, *list_s;
	line_list *head_l, *list_l;
	int lxpz;

	head_s = NULL;
	head_l = NULL;

	ad_xnds(&head_s, &head_l, input);

	list_s = head_s;
	list_l = head_l;

	while (list_l != NULL)
	{
		datash->input = list_l->line;
		datash->args = xlt_xlx(datash->input);
		lxpz = xcx_lnx(datash);
		free(datash->args);

		if (lxpz == 0)
			break;

		xgx_xtz(&list_s, &list_l, datash);

		if (list_l != NULL)
			list_l = list_l->next;
	}

	fr_s_lt(&head_s);
	fr_ne_ls(&head_l);

	if (lxpz == 0)
		return (0);
	return (1);
}

/**
 * xlt_xlx - tokenizes the input string
 *
 * @input: input string.
 * Return: string splitted.
 */
char **xlt_xlx(char *input)
{
	size_t bsize;
	size_t xix;
	char **tokens;
	char *token;

	bsize = TOK_BUFSIZE;
	tokens = malloc(sizeof(char *) * (bsize));
	if (tokens == NULL)
	{
		write(STDERR_FILENO, ": allocation error\n", 18);
		exit(EXIT_FAILURE);
	}

	token = _ttk(input, TOK_DELIM);
	tokens[0] = token;

	for (xix = 1; token != NULL; xix++)
	{
		if (xix == bsize)
		{
			bsize += TOK_BUFSIZE;
			tokens = _reallocdp(tokens, xix, sizeof(char *) * bsize);
			if (tokens == NULL)
			{
				write(STDERR_FILENO, ": allocation error\n", 18);
				exit(EXIT_FAILURE);
			}
		}
		token = _ttk(NULL, TOK_DELIM);
		tokens[xix] = token;
	}

	return (tokens);
}
