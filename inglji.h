#ifndef INGLJI_H
#define INGLJI_H

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <signal.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>
/* deleting the un-neccessary */
#include <string.h>
/* end deleting the un-neccessary */

#define BUFSIZE 1088
extern char **environ;
/**
 *   * struct environ_typing - linked list from PATH
 *     * @str: path in the format /usr/bin
 *       * @len: length of the string
 *         * @next: points to the next node
 * @ljistr: points to the next node
 * @lnlji: points to the next node
 * @ljixt: points to the next node
 */
typedef struct environ_typing
{
		char *ljistr;
			unsigned int lnlji;
				struct environ_typing *ljixt;
} env_t;

/**
 *   * struct builtin_commands - stuct for function pointers
 *     * @cmd_str: commands (env, cd, alias, history)
 *       * @fun: function
 */
typedef struct builtin_commands
{
		char *cmd_str;
			int (*fun)();
} builtin_cmds_t;

/* In buil.c */
int (*ising_builtlji(char *cmd))();
int _exit_ing_lji(char **tokens, env_t *linkedlist_path, char *buffer);
int _env_ing_lji(char **tokens, env_t *environment);
int _cd_ing_lji(char **tokens);

/* In built_2.c */
int _ljienv_usr(char **tokens);
int _als_ing_lji(void);
int _hst_ing_lji(void);
int ingbowlji(void);

/* in environt.c */
env_t *lstlji_frmlji_path(void);
env_t *environ_lkd_list(void);
char *srch_ing(char *cmd, env_t *linkedlist_path);

/* in env_operats.c */
char *_ljigetenving(const char *name);
int _ljisetenving(const char *name, const char *value, int overwrite);

/* in linked_list_operns.c */
env_t *ljiadd_noing(env_t **head, char *str, unsigned int len);
void frlji_lsing(env_t *head);


/* In exljicg.c */
void exljictring(char *argv[], env_t *linkedlist_path);

/* In memory_mannt.c */
void *_rlc(char *ptr, unsigned int old_size, unsigned int new_size);
void _mst(char *str, int fill, int n);
void _mpy(char *dest, char *src, unsigned int bytes);

/* In pljixx.c */
char *_getljixx(int file);
char **pljixx(char *str, char *delim);
void ingljixx(void);

/* In strk.c */
/* Other functions in this file do not need to be referenced. */
char *_stk_r(char *str, char *delim, char **saveptr);

/* In string_operns.c */
int _slji(char *s);
int _srcp(char *s1, char *s2, size_t bytes);
char *_tdp(char *src);
char *_stct_rllc(char *dest, char *src);
int _atlji(char *s);
int _sdgt(int c);

/* In string_opers_2.c */
unsigned int wrd_cnt(char *str);
void inglji_print(const char *str);
int _strlen_const(const char *s);
size_t ljipr_ing(const env_t *h);

#endif

