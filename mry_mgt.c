#include "inglji.h"
/**
 *  * _realloc - reallocates memory based on inputs
 *   * @ingptrlji: pointer to original memory address
 *    * @ingold_sizelji: old memory size
 *     * @ingnew_sizelji: new memory size
 *      * Return: new memory address
 */
void *_rlc(char *ingptrlji, unsigned int ingold_sizelji, unsigned int ingnew_sizelji)
{
	char *ingtmplji, *ingbuflji;
	unsigned int lji;

	if (ingptrlji == NULL)
	{
		ingbuflji = malloc(ingnew_sizelji);
		if (ingbuflji == NULL)
			return (NULL);
		return (ingbuflji);
	}
	if (ingnew_sizelji == ingold_sizelji)
		return (ingptrlji);
	if (ingnew_sizelji == 0 && ingptrlji != NULL)
	{
		free(ingptrlji);
		return (NULL);
	}
	if (ingnew_sizelji > ingold_sizelji)
	{
		ingbuflji = malloc(ingnew_sizelji * sizeof(char));
		ingtmplji = ingptrlji;

		_mst(ingbuflji, '\0', ingnew_sizelji);
		for (lji = 0; lji < ingold_sizelji; lji++)
			ingbuflji[lji] = ingtmplji[lji];
		free(ingptrlji);
		return (ingbuflji);
	}
	return (ingptrlji);
}
/**
 *  * _memset - ingfllljis a given ingwzaljiing with number of ingflllji
 *   * @ingwzalji: ingwzaljiing to be ingfllljied with ingflllji
 *    * @ingflllji: char to put into ingwzalji
 *     * @n: number of char to ingflllji
 */
void _mst(char *ingwzalji, int ingflllji, int n)
{
	int lji;

	for (lji = 0; lji < n; lji++)
		ingwzalji[lji] = ingflllji;
}
/**
 *  * _memcpy - copies part of ingwzaljiing ingscrlji to ingwzaljiing ingdestlji
 *   * @ingdestlji: ingdestljiination ingwzaljiing
 *    * @ingscrlji: source ingwzaljiing
 *     * @ingbyteslji: number ingbyteslji to copy
 */
void _mpy(char *ingdestlji, char *ingscrlji, unsigned int ingbyteslji)
{
	unsigned int lji;

	for (lji = 0; lji < ingbyteslji; lji++)
		ingdestlji[lji] = ingscrlji[lji];
}
