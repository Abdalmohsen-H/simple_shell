#include "myshell.h"

/**
 *clean - free any data avoid memory leaks
 *@cmd_buffer_ptr: pointer to free
 */
void clean(char **cmd_buffer_ptr)
{
	if (*cmd_buffer_ptr != NULL)
	{
		free(*cmd_buffer_ptr);
		*cmd_buffer_ptr = NULL;
	}
	if (copyln)
	{
		free(copyln);
	}
	if (outarr)
	{
		free(outarr);
	}
}

/**
 *execute_cmd - execute command
 *@command: command entered
 *@argv: argv array
 */
void execute_cmd(char *command, char *argv[])
{
	if (execv(command, argv) == -1)/*excute then check if failed*/
	{/*error*/
		perror("execv");
		exit(EXIT_FAILURE);
	}
}

/**
 *my_c_env - print all anv items
 *@envp: array of envs vars
 */
void my_c_env(char *envp[])
{size_t len;
	int i;
	/*loop via envp till a NULL pointer is found*/
	for (i = 0; envp[i] != NULL; i++)
	{
		len = my_c_strlen(envp[i]);
		write(STDOUT_FILENO, envp[i], len);
		write(STDOUT_FILENO, "\n", 1);
	}
}

/**
 *my_c_putchar - prints char to stdout
 *@ch: char to print
 *Return: int num of printed chars
 */
int my_c_putchar(char ch)/*putchar of converted int*/
{ return (write(STDERR_FILENO, &ch, 1));
}

/**
 * my_c_puts - prints a string to stdout
 *@strn: string to print
 */
void my_c_puts(const char *strn)
{	char onechar;

	while (*strn != '\0' || (*strn != '\n'))
	{
		onechar = *strn;
		my_c_putchar(onechar);
		strn++;
	}
	my_c_putchar('\n');
}

