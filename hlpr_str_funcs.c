#include "myshell.h"

/**
 * my_c_strlen - get input string length
 * @strng: input string as char pointer
 * Return: int length of string
 *
 */
int my_c_strlen(const char *strng)
{
	int getlen;

	getlen = 0;
	while (*strng != '\0')
	{
		getlen++;
		strng++;
	}
	return (getlen);
}

/**
 * my_c_strncmp - compare selected num of letters
 * on two strings
 * @strn_2: 2nd string
 * @strn1: 1st input string as char pointer
 * @numb: number of letters used to compare from
 * the 2 strings from the start
 * Return: 0 if match, else -1
 *
 */
int my_c_strncmp(const char *strn1, const char *strn_2, size_t numb)
{size_t x = 0;

	while (strn_2[x] != '\0' && x < numb && strn1[x] != '\0')
	{
		if (strn_2[x] != strn1[x])
			return ((int)(strn1[x] - strn_2[x]));
		x++;
	}
	if (x == numb)
	{return (0);
	}
	if (strn1[x] == '\0' && strn_2[x] == '\0')
	{return (0);
	}
	if (strn1[x] == '\0')
	{
		return (-1);
	}
	return (1);
}

/**
 *my_c_strcmp - compare two strings
 * also ignore trailing whitspace while compare
 * this is different from the actual strlen
 *@str_n1: string 1 as char pointer
 *@strn_n2: 2nd input string
 *Return: 0 if identical strings
 *else return substract value of ascii
 *for first two different chars
 */
int my_c_strcmp(char *str_n1, char *strn_n2)
{
	int z = 0;
	int ret_val = 0;

	while (*(str_n1 + z) == *(strn_n2 + z) &&
			*(str_n1 + z) != '\0' && *(strn_n2 + z) != '\0')
	{
		z++;
	}
	if (*(str_n1 + z) != '\0' && *(strn_n2 + z) != '\0')
	{
		ret_val = *(str_n1 + z) - *(strn_n2 + z);
	}
	return (ret_val);
}

/**
 * my_c_strcpy - copies input string from src to dest
 * @destn: char pointer to destination strng
 * @srce: points to input source string
 * Return: pointer to destn at the end
 */
char *my_c_strcpy(char *destn, char *srce)
{
	int contr = 0;

	while (*(srce + contr))
	{
		*(destn + contr) = *(srce + contr);
		contr++;
	}
	*(destn + contr) = '\0';
	return (destn);
}

/**
 * my_c_strcat - concatnate two strings like
 * builtin strcat func
 * @destn: char pointer to destination strng
 * @srce: points to input source string
 * Return: pointer to the resulting string destn
 */
char *my_c_strcat(char *destn, char *srce)
{
	int z = 0;

	while (*destn != '\0')
	{
		destn++;
		z++;
	}
	while (*srce != '\0')
	{
		*destn = *srce;
		srce++;
		destn++;
		z++;
	}
	*destn = '\0';
	return (destn - z);
}
