#include "myshell.h"
/**
 *too_mny_args - error for too many arguments
 *like shell shows command, line number & prog_name
 *@cmnd: cmd entered
 *@ln_contr: lin num of cmd in case of file input
 */

void too_mny_args(char *cmnd, int ln_contr)
{
	int len = 0;

	len += write(STDERR_FILENO, prog_name, my_c_strlen(prog_name));
	len += write(STDERR_FILENO, ": ", 2);
	len += my_itoa(ln_contr);
	len += write(STDERR_FILENO, ": ", 2);
	len += write(STDERR_FILENO, command, my_c_strlen(cmnd));
	len += write(STDERR_FILENO, ": too many arguments\n", 21);

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
