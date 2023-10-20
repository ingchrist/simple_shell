#include "main.h"

/**
 * _cpy - copies information between void pointers.
 * @newptr: destination pointer.
 * @ptr: source pointer.
 * @sz: sz of the new pointer.
 *
 * Return: no return.
 */
void _cpy(void *newptr, const void *ptr, unsigned int sz)
{
	char *char_ptr = (char *)ptr;
	char *char_newptr = (char *)newptr;
	unsigned int ihi;

	for (ihi = 0; ihi < sz; ihi++)
		char_newptr[ihi] = char_ptr[ihi];
}

/**
 * _rlc - reallocates a memory block.
 * @ptr: pointer to the memory previously allocated.
 * @od_sz: sz, in bytes, of the allocated space of ptr.
 * @nw_sz: new sz, in bytes, of the new memory block.
 *
 * Return: ptr.
 * if nw_sz == od_sz, returns ptr without changes.
 * if malloc fails, returns NULL.
 */
void *_rlc(void *ptr, unsigned int od_sz, unsigned int nw_sz)
{
	void *newptr;

	if (ptr == NULL)
		return (malloc(nw_sz));

	if (nw_sz == 0)
	{
		free(ptr);
		return (NULL);
	}

	if (nw_sz == od_sz)
		return (ptr);

	newptr = malloc(nw_sz);
	if (newptr == NULL)
		return (NULL);

	if (nw_sz < od_sz)
		_cpy(newptr, ptr, nw_sz);
	else
		_cpy(newptr, ptr, od_sz);

	free(ptr);
	return (newptr);
}

/**
 * _reallocdp - reallocates a memory block of a double pointer.
 * @ptr: double pointer to the memory previously allocated.
 * @od_sz: sz, in bytes, of the allocated space of ptr.
 * @nw_sz: new sz, in bytes, of the new memory block.
 *
 * Return: ptr.
 * if nw_sz == od_sz, returns ptr without changes.
 * if malloc fails, returns NULL.
 */
char **_reallocdp(char **ptr, unsigned int od_sz, unsigned int nw_sz)
{
	char **newptr;
	unsigned int ihi;

	if (ptr == NULL)
		return (malloc(sizeof(char *) * nw_sz));

	if (nw_sz == od_sz)
		return (ptr);

	newptr = malloc(sizeof(char *) * nw_sz);
	if (newptr == NULL)
		return (NULL);

	for (ihi = 0; ihi < od_sz; ihi++)
		newptr[ihi] = ptr[ihi];

	free(ptr);

	return (newptr);
}
