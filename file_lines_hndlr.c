#include "myshell.h"

/**
 *file_lines - hlper func to handle lines of file
 *@line: each line of file
 *@envp: env vars
 */
void file_lines(char *line, char *envp[])
{char *copyln;
	while (*line != '\0')
	{char *newline = my_c_strchr(line, '\n');/*find next newline char*/
		if (newline != NULL)
		{*newline = '\0';/*Null-terminate line at \n char */
			copyln = my_c_strdup(line);/*handle the line*/
			if (copyln == NULL)
			{perror("Memory allocation failed.\n");
				exit(EXIT_FAILURE);
			}
			hndle_chld_prcs(copyln, envp);
			free(copyln);
			line = newline + 1;/*Move to the next line*/
		}
		else
		{copyln = my_c_strdup(line);/*handle last line*/
			if (copyln == NULL)
			{perror("Memory allocation failed.\n");
				exit(EXIT_FAILURE);
			}
			hndle_chld_prcs(copyln, envp);
			free(copyln);
			break;
		}
	}
	if (outarr != NULL)
		outarr = NULL;
}
