#include "main.h"

/**
 * _sct - concatenate two strings
 * @dt: char pointer the dt of the copied str
 * @src: const char pointer the source of str
 * Return: the dt
 */
char *_sct(char *dt, const char *src)
{
	int xzx;
	int xjx;

	for (xzx = 0; dt[xzx] != '\0'; xzx++)
		;

	for (xjx = 0; src[xjx] != '\0'; xjx++)
	{
		dt[xzx] = src[xjx];
		xzx++;
	}

	dt[xzx] = '\0';
	return (dt);
}
/**
 * *_sty - Copies the string pointed to by src.
 * @dt: Type char pointer the dt of the copied str
 * @src: Type char pointer the source of str
 * Return: the dt.
 */
char *_sty(char *dt, char *src)
{

	size_t xax;

	for (xax = 0; src[xax] != '\0'; xax++)
	{
		dt[xax] = src[xax];
	}
	dt[xax] = '\0';

	return (dt);
}
/**
 * _rcp - Function that compares two strings.
 * @xs1x: type str compared
 * @xs2x: type str compared
 * Return: Always 0.
 */
int _rcp(char *xs1x, char *xs2x)
{
	int xzx;

	for (xzx = 0; xs1x[xzx] == xs2x[xzx] && xs1x[xzx]; xzx++)
		;

	if (xs1x[xzx] > xs2x[xzx])
		return (1);
	if (xs1x[xzx] < xs2x[xzx])
		return (-1);
	return (0);
}
/**
 * _rcr - locates xax character in xax string,
 * @s: string.
 * @c: character.
 * Return: the pointer to the first occurrence of the character c.
 */
char *_rcr(char *s, char c)
{
	unsigned int xzx = 0;

	for (; *(s + xzx) != '\0'; xzx++)
		if (*(s + xzx) == c)
			return (s + xzx);
	if (*(s + xzx) == c)
		return (s + xzx);
	return ('\0');
}
/**
 * _ttrn - gets the length of xax prefix substring.
 * @s: initial segment.
 * @cpt: accepted bytes.
 * Return: the number of accepted bytes.
 */
int _ttrn(char *s, char *cpt)
{
	int xzx, xjx, bl;

	for (xzx = 0; *(s + xzx) != '\0'; xzx++)
	{
		bl = 1;
		for (xjx = 0; *(cpt + xjx) != '\0'; xjx++)
		{
			if (*(s + xzx) == *(cpt + xjx))
			{
				bl = 0;
				break;
			}
		}
		if (bl == 1)
			break;
	}
	return (xzx);
}
