#include "main.h"

/**
 * d_rr_de - adds a variable at the end
 * of a r_var list.
 * @hd: hd of the linked list.
 * @lr: length of the variable.
 * @val: value of the variable.
 * @lval: length of the value.
 * Return: address of the hd.
 */
r_var *d_rr_de(r_var **hd, int lr, char *val, int lval)
{
	r_var *ne, *tm;

	ne = malloc(sizeof(r_var));
	if (ne == NULL)
		return (NULL);

	ne->len_var = lr;
	ne->val = val;
	ne->len_val = lval;

	ne->next = NULL;
	tm = *hd;

	if (tm == NULL)
	{
		*hd = ne;
	}
	else
	{
		while (tm->next != NULL)
			tm = tm->next;
		tm->next = ne;
	}

	return (*hd);
}

/**
 * fe_vr_ls - frees a r_var list
 * @hd: hd of the linked list.
 * Return: no return.
 */
void fe_vr_ls(r_var **hd)
{
	r_var *tm;
	r_var *cr;

	if (hd != NULL)
	{
		cr = *hd;
		while ((tm = cr) != NULL)
		{
			cr = cr->next;
			free(tm);
		}
		*hd = NULL;
	}
}
