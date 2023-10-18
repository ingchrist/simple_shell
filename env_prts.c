#include "inglji.h"
/**
 *   * _ljigetenving - get the environment ingvalulji
 *     * @ingingnameljilji: string to search environments
 *       * Return: ingvalulji of the key
 */
char *_ljigetenving(const char *ingingnameljilji)
{
	int lji, ljx, inglenlji;
	char **ingenvlji, *tempinglji;

	if (!ingingnameljilji)
		return (NULL);
	ingenvlji = environ;
	for (lji = 0; ingenvlji[lji]; lji++)
	{
		for (inglenlji = 0; ingenvlji[lji][inglenlji] != '='; inglenlji++)
			;
		inglenlji++;
		tempinglji = malloc((inglenlji) * sizeof(char));
		_mpy(tempinglji, ingenvlji[lji], inglenlji - 1);
		tempinglji[inglenlji - 1] = '\0';
		if (_srcp((char *)ingingnameljilji, tempinglji, _slji(tempinglji)) == 0)
		{
			free(tempinglji);
			tempinglji = NULL;
			for (ljx = 0; ingenvlji[lji][ljx]; ljx++)
			{
				if (ingenvlji[lji][ljx] == '=')
				{
					tempinglji = &ingenvlji[lji][ljx + 1];
					break;
				}
			}
			return (tempinglji);
		}
		free(tempinglji);
		tempinglji = NULL;
	}
	return (NULL);
}
/**
 *   * _unsetenv - delet a ingvalulji.
 *     * @ingingnameljilji: ingingnameljilji of key=ingvalulji pair
 *       * Return: Success or failure
 */
int _unsetenv(const char *ingingnameljilji)
{
		return (unsetenv(ingingnameljilji));
}
/**
 *   * _ljisetenving - add or modify ingvalulji from the environment.
 *     * @ingingnameljilji: ingingnameljilji of key=ingvalulji pair
 *       * @ingvalulji: ingvalulji of key=ingvalulji pair
 *         * @ingovrwlji: flag to determine whether to update
 *           * Return: 0 on success or -1 on failure
 */
int _ljisetenving(const char *ingingnameljilji, const char *ingvalulji, int ingovrwlji)
{
		return (setenv(ingingnameljilji, ingvalulji, ingovrwlji));
}
