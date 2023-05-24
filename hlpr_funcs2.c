#include "myshell.h"

/**
 *exit_bltn_error - hndle non numeric exit status err
 *@command: cmd
 *@arg: arg
 */
void exit_bltn_error(char *command, char *arg)
{
	int len = 0;

	len += write(STDERR_FILENO, prog_name, my_c_strlen(prog_name));
	len += write(STDERR_FILENO, ": ", 2);
	len += write(STDERR_FILENO, command, my_c_strlen(command));
	len += write(STDERR_FILENO, ": ", 2);
	len += write(STDERR_FILENO, arg, my_c_strlen(arg));
	len += write(STDERR_FILENO, ": numeric argument required\n", 28);

	if (len < 0)
	{
		perror("Error: Command not found or write failure");
	}
	if (command != NULL)
	{free(command);
		command = NULL;
	}
	if (copyln != NULL)
	{free(copyln);
		copyln = NULL;
	}
	if (outarr != NULL)
	{free(outarr);
		outarr = NULL;
	}
	exit(EXIT_FAILURE);
}

/**
 *my_c_exit - act like exit bultn cmd on shl
 *@args: args of exit
 */
void my_c_exit(char **args)
{char *s;
	int t = 0, ext_status = 0;

	if (args[1] != NULL)
	{s = args[1];
		while ((*(s + t) < '0' || *(s + t) > '9') && (*(s + t) != '\0'))
		{
			if (*(s + t) != '-')
			{
				exit_bltn_error(args[0], args[1]);
			}
			t++;
		}
		ext_status = my_c_atoi(args[1]);
	}
	if (command != NULL)
	{free(command);
		command = NULL;
	}
	if (copyln != NULL)
	{free(copyln);
		copyln = NULL;
	}
	if (outarr != NULL)
	{free(outarr);
		outarr = NULL;
	}
	exit(ext_status);
}


/**
 *my_itoa_recursive - hlpr func for itoa
 *@number: input number
 *Return: int
 */
int my_itoa_recursive(int number)
{
	int digit_ctr = 0;
	char digit_aschar;

	if (number == 0) /*exit Recursion if number == 0 */
	{
		return (digit_ctr);
	}
	/*  recursion to iterate a positive int and extract*/
	/*to get each digit from left to right*/
	digit_ctr = my_itoa_recursive(number / 10);
	/*print the right most digit first, becuase it only one digit*/
	/*dut to recuresion so you could assume it also the most left digit*/
	digit_aschar = '0' + (number % 10);/*digit as char*/
	write(STDERR_FILENO, &digit_aschar, 1);
	/* Increment digit count inside recursion*/
	return (digit_ctr + 1);
}
/**
 *my_itoa - int to ascii converter
 *@number: num to be converted
 *Return: int of num of printed
 *chars represent the input int number
 */
int my_itoa(int number)/*int to ascii converter*/
{
	if (number == 0) /*mostly won't happen in this app as line*/
	{/*start from 1, but this func could need this later*/
		return (write(STDERR_FILENO, "0", 1));
	}
	/* if not zero print digits from left to right*/
	/* using recursion and return len count*/
	return (my_itoa_recursive(number));
}

/**
 * my_c_atoi - for exit status extract numbers
 * from string i.e. ascii
 * and convert the numbers to integer
 * @strn: input string from exit(strn)
 * Return: number as integer
 */
int my_c_atoi(char *strn)
{char *s = strn;
	int y, k, xtrctd_num, sign;

	y = 0;
	xtrctd_num = 0;
	sign = 1;
	/* Skip any leading non-numeric chars except (-)*/
	while ((*(s + y) < '0' || *(s + y) > '9') && (*(s + y) != '\0'))
	{
		if (*(s + y) == '-')/*not needed 4 this proj. but general*/
		{
			sign *= -1;
		}
		y++;
	}
	/* Convert numeric characters to int */
	k = y;
	while ((*(s + k) >= '0') && (*(s + k) <= '9'))
	{
		xtrctd_num = xtrctd_num * 10 + sign * (*(s + k) - '0');
		/*
		 *1st: xtrctd_num * 10 shifts
		 *old numbers to left to add new
		 *
		 * 2nd: *(s + k) get char at j-th position of input str
		 *
		 * (*(s + k) - '0') converts num
		 * from char to int value via subtracting ascii codes
		 */
		k++;
	}
	return (xtrctd_num);
}
