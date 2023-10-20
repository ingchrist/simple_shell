#include "main.h"

/**
 * _sdp - duplicates a str in the heap memory.
 * @s: Type char pointer str
 * Return: duplicated str
 */
char *_sdp(const char *s)
{
	char *ne;
	size_t xlxn;

	xlxn = _xtln(s);
	ne = malloc(sizeof(char) * (xlxn + 1));
	if (ne == NULL)
		return (NULL);
	_cpy(ne, s, xlxn + 1);
	return (ne);
}

/**
 * _xtln - Returns the lenght of a string.
 * @s: Type char pointer
 * Return: Always 0.
 */
int _xtln(const char *s)
{
	int xlxn;

	for (xlxn = 0; s[xlxn] != 0; xlxn++)
	{
	}
	return (xlxn);
}

/**
 * mp_cr - compare chars of strings
 * @str: input string.
 * @dim: delimiter.
 *
 * Return: 1 if are equals, 0 if not.
 */
int mp_cr(char str[], const char *dim)
{
	unsigned int xix, j, xkx;

	for (xix = 0, xkx = 0; str[xix]; xix++)
	{
		for (j = 0; dim[j]; j++)
		{
			if (str[xix] == dim[j])
			{
				xkx++;
				break;
			}
		}
	}
	if (xix == xkx)
		return (1);
	return (0);
}

/**
 * _ttk - splits a string by some delimiter.
 * @str: input string.
 * @dim: delimiter.
 *
 * Return: string splited.
 */
char *_ttk(char str[], const char *dim)
{
	static char *spl, *str_end;
	char *str_start;
	unsigned int xix, bl;

	if (str != NULL)
	{
		if (mp_cr(str, dim))
			return (NULL);
		spl = str; /*Store first address*/
		xix = _xtln(str);
		str_end = &str[xix]; /*Store last address*/
	}
	str_start = spl;
	if (str_start == str_end) /*Reaching the end*/
		return (NULL);

	for (bl = 0; *spl; spl++)
	{
		/*Breaking loop finding the next token*/
		if (spl != str_start)
			if (*spl && *(spl - 1) == '\0')
				break;
		/*Replacing delimiter for null char*/
		for (xix = 0; dim[xix]; xix++)
		{
			if (*spl == dim[xix])
			{
				*spl = '\0';
				if (spl == str_start)
					str_start++;
				break;
			}
		}
		if (bl == 0 && *spl) /*Str != Delim*/
			bl = 1;
	}
	if (bl == 0) /*Str == Delim*/
		return (NULL);
	return (str_start);
}

/**
 * _sgt - defines if string passed is a number
 *
 * @s: input string
 * Return: 1 if string is a number. 0 in other case.
 */
int _sgt(const char *s)
{
	unsigned int xix;

	for (xix = 0; s[xix]; xix++)
	{
		if (s[xix] < 48 || s[xix] > 57)
			return (0);
	}
	return (1);
}
