#include "myshell.h"

/**
 *file_arg - cmds from file as arg
 *@argc: arcs count
 *@argv: args array
 *@envp: env vars
 *@is_intractv: interactive or not
 */
void file_arg(int argc, char *argv[], char *envp[], int *is_intractv)
{int fildscrptr = open(argv[1], O_RDONLY); /*file Descriptor*/
	char bufr[Buf_Sze], *line;
	ssize_t fl_data_byts;/*read file data as bytes*/

	*is_intractv = 0;
	if (argc != 2)
	{write(STDOUT_FILENO, "Usage: ", 7);
		write(STDOUT_FILENO, argv[0], my_c_strlen(argv[0]));
		write(STDOUT_FILENO, " <filename>\n", 12);
		return;
	}
	if (fildscrptr == -1)
	{
		if (errno == ENOENT)
		{write(STDERR_FILENO, prog_name, my_c_strlen(prog_name));
			write(STDERR_FILENO, ": 0: Can't open ", 16);
			write(STDERR_FILENO, argv[1], my_c_strlen(argv[1]));
			write(STDERR_FILENO, "\n", 1);
			exit(127);
		}
		exit(1);
	}
	fl_data_byts = read(fildscrptr, bufr, Buf_Sze - 1);
	if (fl_data_byts == 0)/*empty File - no lines*/
		exit(0);
	else if (fl_data_byts > 0)
	{bufr[fl_data_byts] = '\0'; /* Null-terminate the buffer*/
		line = bufr;/* Handle each line*/
		file_lines(line, envp);
	}
	if (copyln != NULL)
		copyln = NULL;
	if (outarr != NULL)
		outarr = NULL;
	close(fildscrptr);
}
