#include "myshell.h"

/**
 *excte_cmd_nt_fond - error for command not found
 *like shell shows command, line number & prog_name
 *@command: cmd entered
 *@line_number: ln num of cmd in case of file input
 */
void excte_cmd_nt_fond(char *command, int line_number)
{
	int len = 0;

	len += write(STDERR_FILENO, prog_name, my_c_strlen(prog_name));
	len += write(STDERR_FILENO, ": ", 2);
	len += my_itoa(line_number);
	len += write(STDERR_FILENO, ": ", 2);
	len += write(STDERR_FILENO, command, my_c_strlen(command));
	len += write(STDERR_FILENO, ": not found\n", 12);

	if (len < 0)
	{
		perror("Error: Command not found or write failure");
	}
	if (command != NULL)
	{/*free(command);*/
		command = NULL;
	}
	exit(EXIT_FAILURE);
}

/**
 * excte_cmd_wth_slsh - execute cmd with slash
 *@command: cmd
 *@arguments: args array
 *@line_ctr: line count useful 4 files
 *@envp: env vars
 */
void excte_cmd_wth_slsh(char *command, char *arguments[],
		int line_ctr, char *envp[])
{pid_t pid;

	ln_ctr = line_ctr;
	if (my_c_strcmp(command, "/bin/env") == 0)
		my_c_env(envp, arguments, line_ctr);
	if (access(command, X_OK) == 0)
	{
		pid = fork();
		check_child_prcs(pid, command, arguments);
	}
	else
	{
		excte_cmd_nt_fond(command, ln_ctr);
	}
}

/**
 *getpath_fromenvp - get path from envp[]
 *@envp: env vars
 *Return: char *path
 */
char *getpath_fromenvp(char *envp[])
{int idx;
	char *path = NULL;

	for (idx = 0; envp[idx] != NULL; idx++)
	{/*loop all env vars */
		if (my_c_strncmp(envp[idx], "PATH=", 5) == 0)/*till path env var found*/
		{
			path = envp[idx] + 5;/*skip first 5 chars (i.e. skip "PATH=" prefix)*/
			break;
		}
	}
	return (path);
}

/**
 *rmve_trling_nwlne - remove trailing new line
 *@str: string
 *@size: size
 */
void rmve_trling_nwlne(char *str, ssize_t size)
{
	if (str[size - 1] == '\n')
	{
		str[size - 1] = '\0'; /* Remove trailing newline character*/
	}
	else
	{
		str[size] = '\0';
	}
}

/**
 * my_c_strchr - find and locate character
 * in a string, first occurrence,
 * also prints from found till end of string
 * @strng: input string
 * @ch: charcter to seach for
 * Return: address if found, else NULL
 */
char *my_c_strchr(char *strng, char ch)
{
	while (*strng != '\0')
	{
		if (*strng == ch)
		{
			return (strng);
		}
		strng++;
	}
	if (*strng != ch)
		return ('\0');
	return (strng);
}
