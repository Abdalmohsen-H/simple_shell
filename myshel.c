#include "myshell.h"

/**
 *main - entry 4 my own shell
 *@argc: input args count
 *@argv: input args array
 *@envp: env vars array
 *Return: 0 if success , else 1 as failure
 */
int main(int argc, char *argv[], char *envp[])
{size_t cmd_size = 0;/*command size*/
	ssize_t usr_in_size;/* in bytes*/
	int is_intractv = 1;/*interactive mode checker*/

	ctrlc = 0;
	command = NULL;
	ln_ctr = 1;
	prog_name = argv[0];/*excutable filename for error handling(global)*/
	if (argc > 1)/*argument passed to exe. (only files allowed)*/
	{ln_ctr = 1;/*reset global variable*/
		file_arg(argc, argv, envp, &is_intractv);/*handle files*/
	}
	else if (!isatty(fileno(stdin))) /*no file as arg*/
	{is_intractv = 0; /*but piped commands via cat | echo etc.*/
		ln_ctr = 1;/*reset global variable*/
		while ((usr_in_size = getline(&command, &cmd_size, stdin)) != -1)
		{rmve_trling_nwlne(command, usr_in_size);
			hndle_chld_prcs(command, envp);
			ln_ctr++;
		}
	}
	if (is_intractv) /* User on Interactive mode */
	{intractv(envp);/*handle*/
	}
	if (command != NULL)
	{free(command);
		command = NULL;
	}
	return (0);
}
