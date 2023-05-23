#include "myshell.h"
/**
 *check_child_prcs- check child prcs
 *@pid: pid
 *@full_path: full path
 *@arguments: args
 */
void check_child_prcs(pid_t pid, char *full_path, char **arguments)
{
	if (pid < 0)
	{perror("fork");
		exit(EXIT_FAILURE);
	}
	else if (pid == 0)
	{execute_cmd(full_path, arguments);/*in a Child process*/
		exit(EXIT_SUCCESS);
	}
	else /*on a Parent process*/
	{wait(NULL);
	}
}
