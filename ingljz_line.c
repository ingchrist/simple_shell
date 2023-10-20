#include "main.h"

/**
 * bgx_lxn - assigns the line var for get_line
 * @lineptr: Buffer that store the ipt str
 * @buffer: str that is been called to line
 * @n: size of line
 * @tj: size of buffer
 */
void bgx_lxn(char **lineptr, size_t *n, char *buffer, size_t tj)
{

	if (*lineptr == NULL)
	{
		if  (tj > BUFSIZE)
			*n = tj;

		else
			*n = BUFSIZE;
		*lineptr = buffer;
	}
	else if (*n < tj)
	{
		if (tj > BUFSIZE)
			*n = tj;
		else
			*n = BUFSIZE;
		*lineptr = buffer;
	}
	else
	{
		_sty(*lineptr, buffer);
		free(buffer);
	}
}
/**
 * xt_lx - Read inpt from stream
 * @lineptr: buffer that stores the ipt
 * @n: size of lineptr
 * @stream: stream to read from
 * Return: The number of bytes
 */
ssize_t xt_lx(char **lineptr, size_t *n, FILE *stream)
{
	int xwi;
	static ssize_t ipt;
	ssize_t retval;
	char *buffer;
	char t = 'z';

	if (ipt == 0)
		fflush(stream);
	else
		return (-1);
	ipt = 0;

	buffer = malloc(sizeof(char) * BUFSIZE);
	if (buffer == 0)
		return (-1);
	while (t != '\n')
	{
		xwi = read(STDIN_FILENO, &t, 1);
		if (xwi == -1 || (xwi == 0 && ipt == 0))
		{
			free(buffer);
			return (-1);
		}
		if (xwi == 0 && ipt != 0)
		{
			ipt++;
			break;
		}
		if (ipt >= BUFSIZE)
			buffer = _rlc(buffer, ipt, ipt + 1);
		buffer[ipt] = t;
		ipt++;
	}
	buffer[ipt] = '\0';
	bgx_lxn(lineptr, n, buffer, ipt);
	retval = ipt;
	if (xwi != 0)
		ipt = 0;
	return (retval);
}
