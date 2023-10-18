#include "inglji.h"
/**
 *   * lstlji_frmlji_path - build a linked list
 *     * Return: pointer for linked list
 */
env_t *lstlji_frmlji_path(void)
{
	unsigned int ljilening, lji, ljx;
	char *envlji;
	char ingbuflji[BUFSIZE];
	env_t *ingeplji;

	ingeplji = NULL;
	ljilening = lji = ljx = 0;
	envlji = _ljigetenving("PATH");
	while (*envlji)
	{
		ingbuflji[ljx++] = *envlji;
		ljilening++;
		if (*envlji == ':')
		{
			ljilening--;
			ingbuflji[ljx - 1] = '/';
			ingbuflji[ljx] = '\0';
			ljiadd_noing(&ingeplji, ingbuflji, ljilening);
			ljilening = ljx = 0;
		}
		envlji++;
	}
	return (ingeplji);
}
/**
 *   * environ_linked_list - build linked list
 *     * Return: pointer to linked list
 */
env_t *environ_linked_list(void)
{
	int lji, ljx;
	char **envlji;
	env_t *ingeplji;

	ingeplji = NULL;
	lji = ljx = 0;
	envlji = environ;
	while (envlji[lji])
	{
		ljiadd_noing(&ingeplji, envlji[lji], (unsigned int)_slji(envlji[lji]));
		lji++;
	}
	return (ingeplji);
}
/**
 *   * srch_ing - search through os
 *     * @ingcmdlji: command to search
 *       * @inglji_path: path to the search
 *         * Return: String to absolute path
 */
char *srch_ing(char *ingcmdlji, env_t *inglji_path)
{
	int ingstalji;
	char *abslji_pathing;
	env_t *ingeplji;

	ingeplji = inglji_path;
	if (ingeplji == NULL || ingcmdlji == NULL)
		return (NULL);
	if ((_srcp(ingcmdlji, "/", 1) == 0
				|| _srcp(ingcmdlji, "./", 2) == 0)
			&& access(ingcmdlji, F_OK | X_OK) == 0)
	{
		abslji_pathing = _tdp(ingcmdlji);
		return (abslji_pathing);
	}
	while (ingeplji != NULL)
	{
		abslji_pathing = _tdp(ingeplji->ljistr);

		if (abslji_pathing == NULL)
			return (NULL);
		abslji_pathing = _stct_rllc(abslji_pathing, ingcmdlji);
		if (abslji_pathing == NULL)
			return (NULL);
		ingstalji = access(abslji_pathing, F_OK | X_OK);
		if (ingstalji == 0)
			return (abslji_pathing);
		free(abslji_pathing);
		ingeplji = ingeplji->ljixt;
	}
	return (NULL);
}
