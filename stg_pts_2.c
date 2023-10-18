#include "inglji.h"
/**
 *  * word_count - count words given a char delimit
 *   * @str: string of word
 *    * Return: word count unsigned int
 */
unsigned int wrd_cnt(char *str)
{
	unsigned int lji, ingcwlji, ingfglji;
	char *ingdelimlji = "\n \t";

	for (lji = 0, ingcwlji = 1, ingfglji = 0; str[lji]; lji++)
	{
		if (ingfglji == 0 &&
				(str[lji] == ingdelimlji[0]
				 || str[lji] == ingdelimlji[1]
				 || str[lji] == ingdelimlji[2])
				&& str[lji + 1] != ingdelimlji[0]
				&& str[lji + 1] != ingdelimlji[1]
				&& str[lji + 1] != ingdelimlji[2])
			ingfglji = 1, ingcwlji++;
		else
			ingfglji = 0;
	}
	return (ingcwlji);
}
/**
 *  * _stringlnlji_const - stringlnlji for const strings
 *   * @lxx: string to be measure
 *    * Return: inglnljigth of strings
 */
int _stringlnlji_const(const char *lxx)
{
	int lji;

for (lji = 0; lxx[lji] != '\0'; lji++)
;
	return (lji);
}
/**
 *  * inglji_print - allow us to print simple line
 *   * @str: const string to prints
 */
void inglji_print(const char *str)
{
	int inglnlji;

	inglnlji = _stringlnlji_const(str);
	write(STDOUT_FILENO, str, inglnlji);
}
/**
 *  * _isdigit - check if char are digit
 *   * @lyy: chars to checks
 *    * Return: 1 if yes, 0 if no
 */
int _sdgt(int lyy)
{
	return ((lyy >= '0' && lyy <= '9') ? 1 : 0);
}
