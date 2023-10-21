#ifndef _MAIN_H_
#define _MAIN_H_

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <errno.h>
#include <fcntl.h>
#include <signal.h>
#include <limits.h>

#define BUFSIZE 1024
#define TOK_BUFSIZE 128
#define TOK_DELIM " \t\r\n\a"

/* Points to an array of pointers to strings called the "environment" */
extern char **environ;


/**
 * struct data - struct that contains all relevant data on runtime
 * @av: argument vector
 * @input: command line written by the user
 * @args: tokens of the command line
 * @status: last status of the shell
 * @counter: lines counter
 * @_environ: environment variable
 * @pid: process ID of the shell
 */
typedef struct data
{
	char **av;
	char *input;
	char **args;
	int status;
	int counter;
	char **_environ;
	char *pid;
} data_shell;

/**
 * struct sep_list_s - single linked list
 * @separator: ; | &
 * @next: next node
 * Description: single linked list to store separators
 */
typedef struct sep_list_s
{
	char separator;
	struct sep_list_s *next;
} sep_list;

/**
 * struct line_list_s - single linked list
 * @line: command line
 * @next: next node
 * Description: single linked list to store command lines
 */
typedef struct line_list_s
{
	char *line;
	struct line_list_s *next;
} line_list;

/**
 * struct r_var_list - single linked list
 * @len_var: length of the variable
 * @val: value of the variable
 * @len_val: length of the value
 * @next: next node
 * Description: single linked list to store variables
 */
typedef struct r_var_list
{
	int len_var;
	char *val;
	int len_val;
	struct r_var_list *next;
} r_var;

/**
 * struct builtin_s - Builtin struct for command args.
 * @name: The name of the command builtin i.e cd, exit, env
 * @f: data type pointer function.
 */
typedef struct builtin_s
{
	char *name;
	int (*f)(data_shell *datash);
} builtin_t;

/* aux_lists.c */
sep_list *a_sp_nd_d(sep_list **head, char sep);
void fr_s_lt(sep_list **head);
line_list *d_li_de_d(line_list **head, char *line);
void fr_ne_ls(line_list **head);

/* aux_lists2.c */
r_var *d_rr_de(r_var **head, int lvar, char *var, int lval);
void fe_vr_ls(r_var **head);

/* aux_str functions */
char *_sct(char *dest, const char *src);
char *_sty(char *dest, char *src);
int _rcp(char *s1, char *s2);
char *_rcr(char *s, char c);
int _ttrn(char *s, char *accept);

/* aux_mem.c */
void _cpy(void *newptr, const void *ptr, unsigned int size);
void *_rlc(void *ptr, unsigned int old_size, unsigned int new_size);
char **_reallocdp(char **ptr, unsigned int old_size, unsigned int new_size);

/* aux_str2.c */
char *_sdp(const char *s);
int _xtln(const char *s);
int mp_cr(char str[], const char *delim);
char *_ttk(char str[], const char *delim);
int _sgt(const char *s);

/* aux_str3.c */
void v_trg(char *s);

/* check_syntax_error.c */
int rptd_cr(char *input, int i);
int ror_p_p(char *input, int i, char last);
int fi_crh(char *input, int *i);
void pt_ytx_ror(data_shell *datash, char *input, int i, int bool);
int ck_syx_ror(data_shell *datash, char *input);

/* shell_loop.c */
char *witt_cmt(char *in);
void shl_lp(data_shell *datash);

/* read_line.c */
char *rxdx_ltx(int *i_eof);

/* split.c */
char *xsp_crx(char *input, int bool);
void ad_xnds(sep_list **head_s, line_list **head_l, char *input);
void xgx_xtz(sep_list **list_s, line_list **list_l, data_shell *datash);
int xpt_csx(data_shell *datash, char *input);
char **xlt_xlx(char *input);

/* rep_var.c */
void ck_nvx(r_var **h, char *in, data_shell *data);
int cxk_vsz(r_var **h, char *in, char *st, data_shell *data);
char *rld_itz(r_var **head, char *input, char *new_input, int nlen);
char *rwp_vrw(char *input, data_shell *datash);

/* get_line.c */
void bgx_lxn(char **lineptr, size_t *n, char *buffer, size_t j);
ssize_t xt_lx(char **lineptr, size_t *n, FILE *stream);

/* exec_line */
int xcx_lnx(data_shell *datash);

/* cmd_exec.c */
int sx_crx(char *path, int *i);
char *_which(char *cmd, char **_environ);
int ixs_etbl(data_shell *datash);
int ckx_ror_cd(char *dir, data_shell *datash);
int xdx_xc(data_shell *datash);

/* env1.c */
char *_gxtx(const char *name, char **_environ);
int _evxz(data_shell *datash);

/* env2.c */
char *cy_no(char *name, char *value);
void xst_evx(char *name, char *value, data_shell *datash);
int _xvx(data_shell *datash);
int _untvx(data_shell *datash);

/* cd.c */
void cdx_dt(data_shell *datash);
void xcd_tx(data_shell *datash);
void xcd_pvs(data_shell *datash);
void cdx_tx_hm(data_shell *datash);

/* cd_shell.c */
int xcx_sh(data_shell *datash);

/* get_builtin */
int (*get_builtin(char *cmd))(data_shell *datash);

/* _exit.c */
int txt_sh(data_shell *datash);

/* aux_stdlib.c */
int hvt_n(int n);
char *x_to(int n);
int _xti(char *s);

/* aux_error1.c */
char *st_d(data_shell *, char *, char *, char *);
char *ror_g_c(data_shell *datash);
char *ror_n_fd(data_shell *datash);
char *ror_xt_sh(data_shell *datash);

/* aux_error2.c */
char *error_get_alias(char **args);
char *ror_v(data_shell *datash);
char *error_syntax(char **args);
char *error_permission(char **args);
char *ror_pt_1(data_shell *datash);


/* get_error.c */
int gxt_ror(data_shell *datash, int eval);

/* get_sigint.c */
void xt_stx(int sig);

/* aux_help.c */
void ax_hp_v(void);
void x_hp_sv(void);
void a_hp_tv(void);
void u_hp_gl(void);
void x_hp_xt(void);

/* aux_help2.c */
void x_lp(void);
void x_hp_ls(void);
void u_p_c(void);

/* get_help.c */
int gx_hxp(data_shell *datash);

#endif
