#include "inglji.h"
/**
 *   * exljictring - executes a commands
 *    (* by search through PATHs
 *      * @ingargvlji: array of tokens.
 *        * @inglji_path: PATHs in LL form
 *          * Return: 0 on validation, -1 on failure
 */
void exljictring(char *ingargvlji[], env_t *inglji_path)
{
	pid_t inglji_status = 0;
	char *ingljiq_path;

	ingljiq_path = srch_ing(ingargvlji[0], inglji_path);

	if (!ingljiq_path)
	{
		perror("command not found\n");
		return;
	}

	switch (inglji_status = fork())
	{
		case -1:
			perror("fork failed\n");
			break;
		case 0:
			if (execve(ingljiq_path, ingargvlji, environ) == -1)
				perror("execution failed\n");
			break;
		default:
			free(ingljiq_path);
			if (wait(NULL) == -1)
				perror("wait failed\n");
			break;
	}
}
