#include "main.h"

/**
 * v_trg - reverses a string.
 * @s: input string.
 * Return: no return.
 */
void v_trg(char *s)
{
	int ct = 0, xix, xjx;
	char *str, tm;

	while (ct >= 0)
	{
		if (s[ct] == '\0')
			break;
		ct++;
	}
	str = s;

	for (xix = 0; xix < (ct - 1); xix++)
	{
		for (xjx = xix + 1; xjx > 0; xjx--)
		{
			tm = *(str + xjx);
			*(str + xjx) = *(str + (xjx - 1));
			*(str + (xjx - 1)) = tm;
		}
	}
}
