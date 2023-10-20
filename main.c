#include "main.h"

/**
 * fe_dt - frees data structure
 *
 * @datash: data structure
 * Return: no return
 */
void fe_dt(data_shell *datash)
{
	unsigned int xix;

	for (xix = 0; datash->_environ[xix]; xix++)
	{
		free(datash->_environ[xix]);
	}

	free(datash->_environ);
	free(datash->pid);
}

/**
 * sz_da - Initialize data structure
 *
 * @datash: data structure
 * @av: argument vector
 * Return: no return
 */
void sz_da(data_shell *datash, char **av)
{
	unsigned int xix;

	datash->av = av;
	datash->input = NULL;
	datash->args = NULL;
	datash->status = 0;
	datash->counter = 1;

	for (xix = 0; environ[xix]; xix++)
		;

	datash->_environ = malloc(sizeof(char *) * (xix + 1));

	for (xix = 0; environ[xix]; xix++)
	{
		datash->_environ[xix] = _sdp(environ[xix]);
	}

	datash->_environ[xix] = NULL;
	datash->pid = x_to(getpid());
}

/**
 * main - Entry point
 *
 * @ac: argument count
 * @av: argument vector
 *
 * Return: 0 on success.
 */
int main(int ac, char **av)
{
	data_shell datash;
	(void) ac;

	signal(SIGINT, xt_stx);
	sz_da(&datash, av);
	shl_lp(&datash);
	fe_dt(&datash);
	if (datash.status < 0)
		return (255);
	return (datash.status);
}
