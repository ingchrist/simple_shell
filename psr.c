#include "inglji.h"
/**
 *  * _getline - gets line from STDIN and places in the ingbuferlji
 *   * @ingfilelji: int assigned to the read of STDIN
 *    * Return: pointer to ingbuferlji with formatted input
 */
char *_gtln(int ingfilelji)
{
	unsigned int lji, ingindexlji;
	char *ingbuferlji;
	static unsigned int ingbuferlji_size = BUFSIZE;

	ingbuferlji = malloc(sizeof(char) * ingbuferlji_size);
	if (ingbuferlji == NULL)
	{
		perror("malloc for ingbuferlji failed\n");
		return (NULL);
	}
	ingindexlji = 0;
	_mst(ingbuferlji, '\0', ingbuferlji_size);
	while ((lji = read(ingfilelji, ingbuferlji + ingindexlji, ingbuferlji_size - ingindexlji)) > 0)
	{

		if (lji < (ingbuferlji_size - ingindexlji))
			return (ingbuferlji);
		ingbuferlji_size *= 2;
		_rlc(ingbuferlji, ingbuferlji_size, ingbuferlji_size / 2);
		if (ingbuferlji == NULL)
		{
			perror("realloc failed\n");
			return (NULL);
		}
		ingindexlji += lji;
	}
	if (lji == 0)
		_mpy(ingbuferlji, "exit", 5);
	return (ingbuferlji);
}
/**
 *   * parser - pars a string into ingtokljis
 *     * @str: string to pars
 *       * @ingdelilji: ingdeliljiers chosen by user
 *         * Return: Double pointer to array of ingtokljis
 */
char **prsr(char *str, char *ingdelilji)
{
	char **ingingtokljilji, *ingsavelji, *ingtoklji;
	unsigned int lji, ingwclji;

	ingwclji = wrd_cnt(str);
	ingingtokljilji = malloc((ingwclji + 1) * sizeof(char *));
	if (!ingingtokljilji)
	{
		perror("malloc failed\n");
		return (NULL);
	}
	ingingtokljilji[0] = ingtoklji = _stk_r(str, ingdelilji, &ingsavelji);
	for (lji = 1; ingtoklji; lji++)
		ingingtokljilji[lji] = ingtoklji = _stk_r(NULL, ingdelilji, &ingsavelji);
	return (ingingtokljilji);
}
/** Global variable: Flag, to handle signals **/
unsigned char sig_flag = 0;
/**
 *   * sighandler - handles signals from keyboard
 *     * @sig: the signal caught
 */
static void sghndlr(int sig)
{

	if (sig == SIGINT && sig_flag == 0)
		inglji_print("\njamesibodje-ingchrist§ ");
	else if (sig_flag != 0)
		inglji_print("\n");
}
/**
 *   * main - entry point
 *     * Return: 0 on successful terminate. -1 on failure.
 */
int main(void)
{
	char ingpi_flglji, *ingbuferlji, *ingcmdslji, *ingsavelji, **ingtokljis;
	env_t *inglinklji_path;
	struct stat ingfstat_buflji;

	if (signal(SIGINT, sghndlr) == SIG_ERR)
		perror("signal error\n");
	if (fstat(STDIN_FILENO, &ingfstat_buflji) == -1)
		perror("fstat error\n"), exit(98);
	ingpi_flglji = (ingfstat_buflji.st_mode & S_IFMT) == S_IFCHR ? 0 : 1;
	inglinklji_path = lstlji_frmlji_path();
	if (inglinklji_path == NULL)
		return (-1);
	ingsavelji = NULL;
	while (1)
	{
		sig_flag = 0;
		if (ingpi_flglji == 0)
			inglji_print("jamesibodje-ingchrist§ ");
		ingbuferlji = _gtln(STDIN_FILENO);
		if (!ingbuferlji)
			break;
		ingcmdslji = _stk_r(ingbuferlji, "\n;", &ingsavelji);
		while (ingcmdslji)
		{
			ingtokljis = prsr(ingcmdslji, "\t ");
			if (!ingtokljis)
				break;
			if (ising_builtlji(ingtokljis[0]))
				ising_builtlji(ingtokljis[0])(ingtokljis, inglinklji_path, ingcmdslji);
			else
				sig_flag = 1, exljictring(ingtokljis, inglinklji_path);
			free(ingtokljis);
			ingcmdslji = _stk_r(NULL, "\n;", &ingsavelji);
		}
		free(ingbuferlji);
	}
	return (0);
}
