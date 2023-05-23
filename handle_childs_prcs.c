#include "myshell.h"

/**
 *hndle_chld_prcs - exec and manage child prcs
 *
 *(Max_args_Nu - 1) reserves a last index for (NULL) if max
 *arguments reached -exec family func.s like excev needs this
 *@command_line: cmd line
 *@envp: env vars
 */
void hndle_chld_prcs(char *command_line, char *envp[])
{char *commands[Max_COMMANDS_Nu];
	int i, j, command_count = 0, arg_count = 0;
	char *token, *command, *arguments[Max_args_Nu];

	token = strtok(command_line, ";");/* Tokenize command line by ";"*/
	while (token != NULL && command_count < Max_COMMANDS_Nu)
	{commands[command_count++] = token;/*command_count incrmnt nxt line*/
		token = strtok(NULL, ";");
	}
	for (i = 0; i < command_count; i++)/* Process each command separately*/
	{command = strtok(commands[i], " ");
		for (j = 0; j < Max_args_Nu; j++)/*reset arguments before handling new cmd*/
			arguments[j] = NULL;
		arg_count = 0;
		if (command != NULL)
		{arguments[arg_count++] = command;/*arg[0]=cmd & arg_cont icrmnt nxt lne*/
			while (arg_count < Max_args_Nu - 1 &&
					(arguments[arg_count] = strtok(NULL, " ")) != NULL)
			{
				if (arguments[arg_count][0] == '#') /*detect comments*/
				{arguments[arg_count] = NULL;/*this is a comment,stop, we have all args*/
					break;/*comment is discarded*/
				}
				arg_count++;
			}
			arguments[arg_count] = NULL;
			if (command == NULL) /* Empty command, ignore*/
				return;
			if (command[0] == '/')
				excte_cmd_wth_slsh(command, arguments, ln_ctr, envp);
			else
				comnd_no_slsh(command, envp, arguments);
		}
	}
}

