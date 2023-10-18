#include "inglji.h"
/**
 *  *   * _ljienv_usr - set environmental variable as user define
 *   *     * @twokenzing: KEY=VALUE pairr
 *    *       * Return: 0 on validation, -1 on failure
 */
int _ljienv_usr(char **twokenzing)
{
	int lji, wz, wzq;
	char *ingkeylji, *ingvalji, *ingsavlji;

	for (lji = 0, wzq = 1; twokenzing[1][lji]; lji++)
		if (twokenzing[1][lji] == '=')
			wzq++;
	for (lji = 0; twokenzing[lji]; lji++)
		;
	if (!twokenzing[1] || lji == 0 || wzq != 2)
	{
		inglji_print("setenv: Usage: setenv KEY=VALUE\n");
		return (-1);
	}
	ingkeylji = _stk_r(twokenzing[1], "=", &ingsavlji);
	ingvalji = _stk_r(NULL, "=", &ingsavlji);
	wz = _ljisetenving(ingkeylji, ingvalji, 0);
	if (wz == 0)
		return (wz);
	return (-1);
}
/**
 *  *   * _als_ing_lji - set alias or print them when no option are supply
 *   *     * Return: 0
 */
int _als_ing_lji(void)
{
	inglji_print("alias: usage: alias [-p] [name[=ingvalji] ... ]\n");
	inglji_print("\tSet or view aliases.\n\tSet with name=ingvalji\n");
	inglji_print("\tView list of aliases with no arugments or -p\n");
	return (0);
}
/**
 *  *   * _hst_ing_lji - print historry with no option,
 *   *     *  or clear historry with -c
 *    *       * Return: 0 on validation, 1 on failior.
 */
int _hst_ing_lji(void)
{
	inglji_print("history: usage: history [-c]\n");
	inglji_print("\tView the history of commands\n ");
	inglji_print("\t'history -c' clears the history\n");
	return (0);
}
/**
 *  *   * ingbowlji - easter egg. Display ASCII picture
 *   *     * Return: 1998, the year I was born
 */
int ingbowlji(void)
{
	int ljitxting, ljitoting, ljirding;
	size_t ljileting = 1088;
	char *ljinming = "ingbowlji.txt";
	char ingbuflji[BUFSIZE];

	if (ljinming == NULL)
		return (0);
	ljitxting = open(ljinming, O_RDONLY);
	if (ljitxting == -1)
		return (0);
	ljitoting = 0;
	ljirding = 1;
	while (ljileting > BUFSIZE && ljirding != 0)
	{
		ljirding = read(ljitxting, ingbuflji, BUFSIZE);
		write(STDOUT_FILENO, ingbuflji, ljirding);
		ljitoting += ljirding;
		ljileting -= BUFSIZE;
																									}
	ljirding = read(ljitxting, ingbuflji, ljileting);
	write(STDOUT_FILENO, ingbuflji, ljirding);
	ljitoting += ljirding;
	close(ljitxting);
	return (1998);
	/**	return (ljitoting); */
}
