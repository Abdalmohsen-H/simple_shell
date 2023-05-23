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
	char bufr[Buf_Sze];
	ssize_t fl_data_byts;/*read file data as bytes*/
	char *line;

	*is_intractv = 0;
	if (argc != 2)
	{
		write(STDOUT_FILENO, "Usage: ", 7);
		write(STDOUT_FILENO, argv[0], my_c_strlen(argv[0]));
		write(STDOUT_FILENO, " <filename>\n", 12);
		return;
	}
	if (fildscrptr == -1)
	{
		write(STDERR_FILENO, "Failed to open the input file: \n", 31);
		return;
	}
	while ((fl_data_byts = read(fildscrptr, bufr, Buf_Sze - 1)) > 0)
	{bufr[fl_data_byts] = '\0'; /* Null-terminate the buffer*/
		line = bufr;/* Handle each line*/
		file_lines(line, envp);
	}
	if (copyln != NULL)
	{free(copyln);
		copyln = NULL;
	}
	if (outarr != NULL)
	{free(outarr);
		outarr = NULL;
	}
	close(fildscrptr);
}
