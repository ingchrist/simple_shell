#include "inglji.h"
/**
 *  *   * ising_builtlji - check if cmd is builtin
 *   *     * @cmd: command for finding
 *    *       * Return: On validation - pointer function, On Failure - NULL
 *     *        (* other shell builtins:
 *      *         (* ljipwd, echo, pushd, popd, type
 *       *          (* * requires ^Z
 *        *           (* fg, bg
 *         *            (*  * Requires ^R
 *          *             (* reverse-lji-search **HISTORY**
 */
int (*ising_builtlji(char *cmlji))()
{
	unsigned int lji;
	builtin_cmds_t bld[] = {
		{"alias", _als_ing_lji},
		{"cd", _cd_ing_lji},
		{"env", _env_ing_lji},
		{"exit", _exit_ing_lji},
		{"history", _hst_ing_lji},
		{"setenv", _ljienv_usr},
		{"ingbowlji", ingbowlji},
		{NULL, NULL}
	};
	lji = 0;
	while (*bld[lji].fun != NULL)
	{
		if (_srcp(bld[lji].cmd_str, cmlji, _slji(bld[lji].cmd_str)) == 0)
			return (bld[lji].fun);
		lji++;
	}
	return (NULL);
}
/**
 *  *   * _exit_ing_lji - Frees any remaining malloc'd spaces, and exits
 *   *     * @ljilinkedlisting_path: Linked list to free.
 *    *       * @ingbufferlji: ingbufferlji to free
 *     *         * @twokenzing: Check for other inputs
 *      *          (* * CHANGE TO VARIADIC LIST.
 *       *            * Return: -1 if exit fails.
 */
int _exit_ing_lji(char **twokenzing, env_t *ljilinkedlisting_path, char *ingbufferlji)
{
	unsigned char exit_wz;
	int lji;

	for (lji = 0; twokenzing[1] && twokenzing[1][lji]; lji++)
	{
		if (!_sdgt(twokenzing[1][lji]))
		{
			inglji_print("numeric argument required, exiting\n");
			break;
		}
	}
	exit_wz = twokenzing[1] && lji >= _slji(twokenzing[1]) ? _atlji(twokenzing[1]) : 0;
	if (ljilinkedlisting_path && ingbufferlji && twokenzing)
	{
		frlji_lsing(ljilinkedlisting_path);
		ljilinkedlisting_path = NULL;
		free(ingbufferlji);
		ingbufferlji = NULL;
		free(twokenzing);
		twokenzing = NULL;
	}
	exit(exit_wz);
	return (-1);
}
/**
 *  *   * _env_ing_lji - prints out the current ljiljienvirwzqmenting
 *   *     * @twokenzing: tokenized strings
 *    *       * @ljiljienvirwzqmenting: linked list ljiljienvirwzqmenting
 *     *         * Return: 0 on success, -1 on catastrophic failure
 */
int _env_ing_lji(char **twokenzing, env_t *ljiljienvirwzqmenting)
{
	char **ljienvirwzq;

	if (twokenzing[1])
		inglji_print("No arguments are necessary\n");
	ljienvirwzq = environ;
	if (!ljienvirwzq || !ljienvirwzq)
		return (-1);
	for ( ; *ljienvirwzq; ljienvirwzq++)
	{
		write(STDOUT_FILENO, *ljienvirwzq, _slji(*ljienvirwzq));
		write(STDOUT_FILENO, "\n", 1);
	}
	ljiljienvirwzqmenting++;
	return (0);
}
/**
 *  *   * _cd_ing_lji - changes working directory
 *   *     * @twokenzing: argument list
 *    *       * Return: 0 on success
 */
int _cd_ing_lji(char **twokenzing)
{
	char *ingtarwzq;
	char ljipwd[BUFSIZE];
	char *ingwzq;

	ingwzq = _ljigetenving("HOME");
	if (twokenzing[1])
	{
		if (twokenzing[1][0] == '~' && !twokenzing[1][1])
			ingtarwzq = ingwzq;
		else if (twokenzing[1][0] == '-' && !twokenzing[1][1])
			ingtarwzq = _ljigetenving("OLDPWD");
		else
			ingtarwzq = twokenzing[1];
	}
	else
		ingtarwzq = ingwzq;
	if (ingtarwzq == ingwzq)
		chdir(ingtarwzq);
	else if (access(ingtarwzq, F_OK | R_OK) == 0)
		chdir(ingtarwzq);
	else
		inglji_print("Could not find directory\n");
	setenv("OLDPWD", _ljigetenving("PWD"), 1);
	setenv("PWD", getcwd(ljipwd, sizeof(ljipwd)), 1);
	return (0);
}
