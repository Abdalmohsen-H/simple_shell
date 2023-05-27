#ifndef custom_header_shell
#define custom_header_shell

/* libs */
#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>
#include <signal.h>
#include <stddef.h>

/* ---*/
#define Max_CMD_LEN 130
#define Max_COMMANDS_Nu 10
#define Max_args_Nu 10
#define Buf_Sze 1024

/*--global vars-*/
char *prog_name; /* program name as Global variable */
int ln_ctr; /*no. of line in every command input cycle*/
char *command;
int ctrlc;
extern char **environ;
char *copyln;
char *outarr;

/* -- funcs --*/
void clean(char **cmd_buffer_ptr);
int my_c_strlen(const char *strng);
int my_c_strncmp(const char *strn1, const char *strn_2, size_t numb);
int my_c_strcmp(char *str_n1, char *strn_n2);
char *my_c_strcpy(char *destn, char *srce);
void execute_cmd(char *command, char *argv[]);
char *my_c_strcat(char *destn, char *srce);
int my_c_putchar(char ch);
void my_c_puts(const char *strn);
int my_itoa_recursive(int number);
int my_itoa(int number);
int my_c_atoi(char *strn);
char *getpath_fromenvp(char *envp[]);
void my_c_env(char *envp[], char *argus[], int line_cntr);
void exit_bltn_error(char *command, char *arg);
void my_c_exit(char **args, int line_contr);
void excte_cmd_nt_fond(char *command, int line_number);
void too_mny_args(char *cmnd, int ln_contr);
void check_child_prcs(pid_t pid, char *full_path, char **arguments);
void comnd_no_slsh(char *command, char *envp[], char *arguments[]);
void excte_cmd_wth_slsh(char *command, char *arguments[],
		int ln_ctr, char *envp[]);
void hndle_chld_prcs(char *command_line, char *envp[]);
void rmve_trling_nwlne(char *str, ssize_t size);
char *my_c_strchr(char *strng, char ch);
char *my_c_strdup(char *str);
void file_lines(char *line, char *envp[]);
void file_arg(int argc, char *argv[], char *envp[], int *is_intractv);
void sgnl_hndlr(int sig_numbr);
void intractv(char *envp[]);
int main(int argc, char *argv[], char *envp[]);
void my_c_cd(char *arguments[]);
#endif
