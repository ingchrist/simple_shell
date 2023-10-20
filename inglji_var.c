#include "main.h"

/**
 * ck_nvx - checks if the typed variable is an env variable
 *
 * @h: head of linked list
 * @in: input string
 * @data: data structure
 * Return: no return
 */
void ck_nvx(r_var **h, char *in, data_shell *data)
{
	int row, chr, j, lval;
	char **_envr;

	_envr = data->_environ;
	for (row = 0; _envr[row]; row++)
	{
		for (j = 1, chr = 0; _envr[row][chr]; chr++)
		{
			if (_envr[row][chr] == '=')
			{
				lval = _xtln(_envr[row] + chr + 1);
				d_rr_de(h, j, _envr[row] + chr + 1, lval);
				return;
			}

			if (in[j] == _envr[row][chr])
				j++;
			else
				break;
		}
	}

	for (j = 0; in[j]; j++)
	{
		if (in[j] == ' ' || in[j] == '\t' || in[j] == ';' || in[j] == '\n')
			break;
	}

	d_rr_de(h, j, NULL, 0);
}

/**
 * cxk_vsz - check if the typed variable is $$ or $?
 *
 * @h: head of the linked list
 * @in: input string
 * @st: last status of the Shell
 * @data: data structure
 * Return: no return
 */
int cxk_vsz(r_var **h, char *in, char *st, data_shell *data)
{
	int xix, lst, lpd;

	lst = _xtln(st);
	lpd = _xtln(data->pid);

	for (xix = 0; in[xix]; xix++)
	{
		if (in[xix] == '$')
		{
			if (in[xix + 1] == '?')
				d_rr_de(h, 2, st, lst), xix++;
			else if (in[xix + 1] == '$')
				d_rr_de(h, 2, data->pid, lpd), xix++;
			else if (in[xix + 1] == '\n')
				d_rr_de(h, 0, NULL, 0);
			else if (in[xix + 1] == '\0')
				d_rr_de(h, 0, NULL, 0);
			else if (in[xix + 1] == ' ')
				d_rr_de(h, 0, NULL, 0);
			else if (in[xix + 1] == '\t')
				d_rr_de(h, 0, NULL, 0);
			else if (in[xix + 1] == ';')
				d_rr_de(h, 0, NULL, 0);
			else
				ck_nvx(h, in + xix, data);
		}
	}

	return (xix);
}

/**
 * rld_itz - replaces string into variables
 *
 * @head: head of the linked list
 * @input: input string
 * @new_input: new input string (replaced)
 * @nlen: new length
 * Return: replaced string
 */
char *rld_itz(r_var **head, char *input, char *new_input, int nlen)
{
	r_var *indx;
	int xix, j, k;

	indx = *head;
	for (j = xix = 0; xix < nlen; xix++)
	{
		if (input[j] == '$')
		{
			if (!(indx->len_var) && !(indx->len_val))
			{
				new_input[xix] = input[j];
				j++;
			}
			else if (indx->len_var && !(indx->len_val))
			{
				for (k = 0; k < indx->len_var; k++)
					j++;
				xix--;
			}
			else
			{
				for (k = 0; k < indx->len_val; k++)
				{
					new_input[xix] = indx->val[k];
					xix++;
				}
				j += (indx->len_var);
				xix--;
			}
			indx = indx->next;
		}
		else
		{
			new_input[xix] = input[j];
			j++;
		}
	}

	return (new_input);
}

/**
 * rwp_vrw - calls functions to replace string into vars
 *
 * @input: input string
 * @dah: data structure
 * Return: replaced string
 */
char *rwp_vrw(char *input, data_shell *dah)
{
	r_var *head, *indx;
	char *status, *new_input;
	int olen, nlen;

	status = x_to(dah->status);
	head = NULL;

	olen = cxk_vsz(&head, input, status, dah);

	if (head == NULL)
	{
		free(status);
		return (input);
	}

	indx = head;
	nlen = 0;

	while (indx != NULL)
	{
		nlen += (indx->len_val - indx->len_var);
		indx = indx->next;
	}

	nlen += olen;

	new_input = malloc(sizeof(char) * (nlen + 1));
	new_input[nlen] = '\0';

	new_input = rld_itz(&head, input, new_input, nlen);

	free(input);
	free(status);
	fe_vr_ls(&head);

	return (new_input);
}
