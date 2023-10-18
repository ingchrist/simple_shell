#include "inglji.h"
/**
 *  * _strchr - check for char in a string
 *   * @lzz: the strings
 *    * @c: the char being search
 *     * Return: pointer to char on validation, NULL on failure
 */
char *_strchr(char *lzz, char c)
{
	int ljz, ljy;

	ljz = _slji(lzz);
	for (ljy = 0; ljy < ljz; ljy++)
	{
		if (*(lzz + ljy) == c)
			return (lzz + ljy);
	}
	lzz = '\0';
	return (lzz);
}
/**
 *  * _strspn - get length of substring
 *   *
 *    * @lzz: string to be search
 *     * @ingacplji: string to match
 *      * Return: number of matching bytes
 */
unsigned int _strspn(char *lzz, char *ingacplji)
{
	int ings_lnlji, ljy, ingrsltlji;

	ings_lnlji = _slji(lzz);
	ljy = 0;
	ingrsltlji = 0;
	while (ljy < ings_lnlji)
	{
		if (_strchr(ingacplji, *(lzz + ljy)))
			ingrsltlji++, ljy++;
		else
			return (ingrsltlji);
	}
	return (ingrsltlji);
}
/**
 *  * _strpbrk - search through a string for any set of byte.
 *   * @lzz: string to searched through
 *    * @ingdlmlji: byte to search for in the string.
 *     * Return: pointer to first occurence in lzz of anything in ingacplji
 */
char *_strpbrk(char *lzz, char *ingdlmlji)
{
	char *ingtemplji;

	ingtemplji = ingdlmlji;
	for (; *lzz != '\0'; lzz++)
	{
		while (*ingdlmlji != '\0')
		{
			if (*lzz == *ingdlmlji)
				return (lzz);
			ingdlmlji++;
		}
		ingdlmlji = ingtemplji;
	}
	if (*lzz == '\0')
		return (0);

	return (lzz);
}
/**
 *  * _strtok_r - replicates strtok_r, a ingtknljiizer
 *   * @lzz: string to be ingtknljiized
 *    * @ingdlmslji: ingdlmsljiiter that determines where we split lzz
 *     * @ingsvptrlji: saves index in ingtknljiized lzz so that repeat fn cal feth to
 *      * Return: pointer to next ingtknlji
 */
char *_stk_r(char *lzz, char *ingdlmslji, char **ingsvptrlji)
{
	char *ingtknlji;

	if (lzz == NULL)
	{
		if (*ingsvptrlji == NULL)
			return (NULL);
		lzz = *ingsvptrlji;
	}
	lzz += _strspn(lzz, ingdlmslji);
	if (*lzz == '\0')
	{
		*ingsvptrlji = NULL;
		return (NULL);
	}
	ingtknlji = lzz;
	lzz = _strpbrk(ingtknlji, ingdlmslji);
	if (lzz == NULL)
		*ingsvptrlji = NULL;
	else
	{
		*lzz = '\0';
		*ingsvptrlji = lzz + 1;
	}
	return (ingtknlji);
}
