#include "myshell.h"

/**
 *comnd_no_slsh - command_no_slash
 *@command: cmd
 *@envp: env vars array
 *@arguments: args list
 */
void comnd_no_slsh(char *command, char *envp[], char *arguments[])
{char *path = getpath_fromenvp(envp), full_path[Max_CMD_LEN];
	char *path_token = strtok(path, ":");
	pid_t pid;/*process ID*/
	int indx;

	if (my_c_strcmp(command, "env") == 0)
	{my_c_env(envp, arguments, ln_ctr);
		return;
	}
	if (my_c_strcmp(command, "exit") == 0)
		my_c_exit(arguments, ln_ctr);
	while (path_token != NULL)
	{my_c_strcpy(full_path, "/bin/");
		my_c_strcat(full_path, command);
		if (access(full_path, X_OK) == 0)
		{pid = fork();
			check_child_prcs(pid, full_path, arguments);
			break; /* Exit loop after execting command*/
		}
		else
		{
			for (indx = 0; indx < Max_CMD_LEN; indx++)
			{full_path[indx] = '\0';/*reset full path*/
			}
			my_c_strcpy(full_path, "/sbin/");
			my_c_strcat(full_path, command);
			if (access(full_path, X_OK) == 0)
			{pid = fork();
				check_child_prcs(pid, full_path, arguments);
				break; /* Exit loop after execting command*/
			}
			else
			{excte_cmd_nt_fond(command, ln_ctr);
			}
		}
		path_token = strtok(NULL, ":");
	}
}
