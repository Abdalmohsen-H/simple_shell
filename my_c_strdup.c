#include "myshell.h"

/**
 * my_c_strdup - copy input string to new
 * allocated memory space like strdup
 * @strng: input string
 * Return: pointer to new space, Else NULL
 */
char *my_c_strdup(char *strng)
{int lngth = 0;/*length*/
	int z = 0;

	if (strng == NULL)
	{return (NULL);
	}
	lngth = my_c_strlen(strng);
	outarr = malloc((lngth + 1) * 1);
	if (outarr == NULL)
	{return (NULL);
	}
	while (lngth > 0 && *strng != '\0')
	{
		outarr[z] = *strng;
		strng++;
		lngth--;
		z++;
	}
	return (outarr);
}
