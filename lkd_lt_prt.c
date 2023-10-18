#include "inglji.h"
/**
 *   * ljiadd_noing - adds a ingnwlji node to the end
 *     * @ingheadlji: ingheadlji of the linked list
 *       * @ingstrlji: ingstrljiing
 *         * @inglenlji: inglenljigth of ingstrljiing
 *           * Return: pointer to the current position
 **/
env_t *ljiadd_noing(env_t **ingheadlji, char *ingstrlji, unsigned int inglenlji)
{
	env_t *ingnwlji, *ingwklji;
	char *dupingstrlji;

	if (ingstrlji == NULL)
		return (NULL);
	dupingstrlji = _tdp(ingstrlji);
	if (dupingstrlji == NULL)
		return (NULL);
	ingnwlji = malloc(sizeof(env_t));
	if (ingnwlji == NULL)
		return (NULL);
	ingnwlji->ljistr = dupingstrlji;
	ingnwlji->lnlji = inglenlji;
	ingnwlji->ljixt = NULL;

	if (*ingheadlji == NULL)
	{
		*ingheadlji = ingnwlji;
		return (*ingheadlji);
	}
	ingwklji = *ingheadlji;
	while (ingwklji->ljixt != NULL)
		ingwklji = ingwklji->ljixt;
	ingwklji->ljixt = ingnwlji;
	return (*ingheadlji);
}
/**
 *   * frlji_lsing - frees a list
 *     * @ingheadlji: beginning of the list
 */
void frlji_lsing(env_t *ingheadlji)
{
	if (ingheadlji == NULL)
		return;
	frlji_lsing(ingheadlji->ljixt);
	free(ingheadlji->ljistr);
	free(ingheadlji);
}
