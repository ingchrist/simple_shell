#include "main.h"

/**
 * hvt_n - Get the lnt of a number.
 * @n: type int number.
 * Return: Lenght of a number.
 */
int hvt_n(int n)
{
	unsigned int kw;
	int lnt = 1;

	if (n < 0)
	{
		lnt++;
		kw = n * -1;
	}
	else
	{
		kw = n;
	}
	while (kw > 9)
	{
		lnt++;
		kw = kw / 10;
	}

	return (lnt);
}
/**
 * x_to - function converts int to string.
 * @n: type int number
 * Return: String.
 */
char *x_to(int n)
{
	unsigned int kw;
	int lnt = hvt_n(n);
	char *bf;

	bf = malloc(sizeof(char) * (lnt + 1));
	if (bf == 0)
		return (NULL);

	*(bf + lnt) = '\0';

	if (n < 0)
	{
		kw = n * -1;
		bf[0] = '-';
	}
	else
	{
		kw = n;
	}

	lnt--;
	do {
		*(bf + lnt) = (kw % 10) + '0';
		kw = kw / 10;
		lnt--;
	}
	while (kw > 0)
		;
	return (bf);
}

/**
 * _xti - converts a string to an integer.
 * @s: input string.
 * Return: integer.
 */
int _xti(char *s)
{
	unsigned int ct = 0, sz = 0, zoz = 0, zn = 1, zm = 1, wzw;

	while (*(s + ct) != '\0')
	{
		if (sz > 0 && (*(s + ct) < '0' || *(s + ct) > '9'))
			break;

		if (*(s + ct) == '-')
			zn *= -1;

		if ((*(s + ct) >= '0') && (*(s + ct) <= '9'))
		{
			if (sz > 0)
				zm *= 10;
			sz++;
		}
		ct++;
	}

	for (wzw = ct - sz; wzw < ct; wzw++)
	{
		zoz = zoz + ((*(s + wzw) - 48) * zm);
		zm /= 10;
	}
	return (zoz * zn);
}
