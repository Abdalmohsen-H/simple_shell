#include "myshell.h"
/**
 *sgnl_hndlr - signal handling func
 *@sig_numbr: signal num
 */
void sgnl_hndlr(int sig_numbr)
{
	if (sig_numbr == 2)
	{ctrlc = 1;
		write(STDOUT_FILENO, "\n($) ", 5);
		fflush(stdout);
		/*clean(&command);*/
		/*print f("Received signal %d, clean.\n", sig);*/
	}
}
