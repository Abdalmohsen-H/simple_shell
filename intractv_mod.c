#include "myshell.h"

/**
 *intractv - handle intractive mode
 *@envp: env vars array
 */
void intractv(char *envp[])
{char *command = NULL;
	size_t cmd_size = 0;/*command size*/
	ssize_t usr_in_size;/* in bytes*/
	/*int itr;*/

	/*signal handlers 4 all signals*/
	/*for (itr = 1; itr < NSIG; itr++)*/
	/*signal(itr, sgnl_hndlr);*/
	signal(SIGINT, sgnl_hndlr);/*handle ctr+c*/
	ln_ctr = 1;/*reset global variable*/
	while (1) /*infinite loop till exit*/
	{write(STDOUT_FILENO, "($) ", 4); /* Print prompt */
		fflush(stdout);/*force -Writes pending stdout data to console*/
		usr_in_size = getline(&command, &cmd_size, stdin);
		if (ctrlc == 1)
		{ctrlc = 0;
			continue;
		}
		else if (usr_in_size == -1)
		{/* End-of-file reached */
			if (errno == 0 || errno == EINVAL || errno == EOF)
			{clean(&command);
				write(STDOUT_FILENO, "\n", 1);
				exit(127);
			}
			else/*Error while reading from stream*/
			{clean(&command);
				perror("getline error\n");
				exit(EXIT_FAILURE);
			}
		}
		else if (usr_in_size == 1 && command[0] == '\n')
			continue; /* Usr just pressed "Enter"*/

		rmve_trling_nwlne(command, usr_in_size);/*Data read successfully*/
		hndle_chld_prcs(command, envp);
		clean(&command);
	}
}
