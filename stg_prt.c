#include "inglji.h"
/**
 *  * _strlen - replicat strlen from the standard library
 *   * @lxx: string to be measure
 *    * Return: length of strin
 */
int _slji(char *lxx)
{
	int lji;

	for (lji = 0; *lxx; lxx++, lji++)
		;
	return (lji);
}
/**
 *  * _strncmp - compares two strings and returns their difference
 *   * @ings1lji: the first string
 *    * @ings2lji: the second string
 *     * @ingbytlji: number of ingbytlji to compare
 *      * Return: number of ingbytlji that differ
 */
int _srcp(char *ings1lji, char *ings2lji, size_t ingbytlji)
{
	unsigned int lji;

	if (ings1lji == NULL || ings2lji == NULL)
		return (-1);
for (lji = 0; ings1lji[lji] && ings2lji[lji] && ings2lji[lji] == ings1lji[lji] && lji < ingbytlji - 1; lji++)
;
	return (ings2lji[lji] - ings1lji[lji]);
}
/**
 *   * _strdup - duplicates a string
 *     * @src: source to copy from
 *       * Return: pointer to malloc'd space
 **/
char *_tdp(char *src)
{
	int lja, lji;
	char *ingdstlji;

	if (src == NULL)
		return (NULL);
	lja = _slji(src);
	if (lja < 0)
		return (NULL);
	lja++;
	ingdstlji = malloc((lja) * sizeof(char));
	if (ingdstlji == NULL)
		return (NULL);
	for (lji = 0; lji < lja; lji++)
		ingdstlji[lji] = src[lji];
	ingdstlji[lji - 1] = '\0';
	return (ingdstlji);
}
/**
 *   * _strcat_realloc - concatenates 2 strings and reallocates automatically
 *     * @ingdstlji: ingdstljiination to copy to
 *       * @src: source to copy from
 *         * Return: pointer to concatenated strings
 **/
char *_stct_rllc(char *ingdstlji, char *src)
{
	unsigned int ingdstlji_len, inglen_scrlji, lji;

	ingdstlji_len = _slji(ingdstlji);
	inglen_scrlji = _slji(src);
	ingdstlji = _rlc(ingdstlji, ingdstlji_len, ingdstlji_len + inglen_scrlji + 1);
	if (ingdstlji == NULL)
		return (NULL);
	for (lji = 0; lji < inglen_scrlji; lji++)
	{
		ingdstlji[lji + ingdstlji_len] = src[lji];
	}
	ingdstlji[lji + ingdstlji_len] = '\0';
	return (ingdstlji);
}
/**
 *  * _atoi - converts a string to an integer
 *   * @lxx: the input string
 *    * Return: the converted int
 */
int _atlji(char *lxx)
{
	int lje, sign, ingrstlji;

	for (lje = ingrstlji = 0, sign = 1; lxx[lje]; lje++)
	{
		if (lxx[lje] == '-')
			sign *= -1;
		if (lxx[lje] >= '0' && lxx[lje] <= '9')
			ingrstlji = 10 * ingrstlji - (lxx[lje] - '0');
		if (ingrstlji < 0 && (lxx[lje] < '0' || lxx[lje] > '9'))
			break;
	}
	if (sign > 0)
		ingrstlji *= -1;
	return (ingrstlji);
}
