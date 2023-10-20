#include "main.h"

/**
 * a_sp_nd_d - adds a separator found at the end
 * of a sep_list.
 * @hd: hd of the linked list.
 * @ijp: separator found (; | &).
 * Return: address of the hd.
 */
sep_list *a_sp_nd_d(sep_list **hd, char ijp)
{
	sep_list *ne, *tm;

	ne = malloc(sizeof(sep_list));
	if (ne == NULL)
		return (NULL);

	ne->separator = ijp;
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
 * fr_s_lt - frees a sep_list
 * @hd: hd of the linked list.
 * Return: no return.
 */
void fr_s_lt(sep_list **hd)
{
	sep_list *tm;
	sep_list *cr;

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

/**
 * d_li_de_d - adds a command line at the end
 * of a line_list.
 * @hd: hd of the linked list.
 * @line: command line.
 * Return: address of the hd.
 */
line_list *d_li_de_d(line_list **hd, char *line)
{
	line_list *ne, *tm;

	ne = malloc(sizeof(line_list));
	if (ne == NULL)
		return (NULL);

	ne->line = line;
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
 * fr_ne_ls - frees a line_list
 * @hd: hd of the linked list.
 * Return: no return.
 */
void fr_ne_ls(line_list **hd)
{
	line_list *tm;
	line_list *cr;

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
