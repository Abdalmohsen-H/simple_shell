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

/**
 *my_c_cd - my_c_chngdirectory
 *@arguments: args list
 */
void my_c_cd(char *arguments[])
{char *dir, *hom_direc, **envarry, *crnt_dirc = getcwd(NULL, 0);

	for (envarry = environ; *envarry != NULL; envarry++)
	{/* get usr home directry*/
		if (my_c_strncmp(*envarry, "HOME=", 5) == 0)
		{hom_direc = my_c_strchr(*envarry, '=') + 1;
			break;
		}
	}
	if (arguments[1] == NULL)/*user didn't input arg with cd*/
	{dir = hom_direc;
		chdir(hom_direc);
	}
	else
	{
		if (my_c_strcmp(arguments[1], "-") == 0)/*user used "-" input arg with cd*/
		{dir = crnt_dirc;
			chdir(crnt_dirc);
		}
		else /*change dir to what user entered*/
		{dir = arguments[1];
			chdir(arguments[1]);
		}
	}
	if (write(STDOUT_FILENO, dir, my_c_strlen(dir)) < 0)
	{perror("write error on cd func");
		exit(1);
	}
	write(STDOUT_FILENO, "\n", 1);
	fflush(stdout);
}
