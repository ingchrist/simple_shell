#include "main.h"

/**
 * xt_stx - Handle the crtl + c call in prompt
 * @sxz: Signal handler
 */
void xt_stx(int sxz)
{
	(void)sxz;
	write(STDOUT_FILENO, "\n^-^ ", 5);
}
