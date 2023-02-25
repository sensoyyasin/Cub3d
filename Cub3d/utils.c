#include "cub3d.h"

char *clear_endstr(char *str)
{
	char *newstr;
	int (i) = 0;
	while (str[i])
	{
		if(str[i] <= 32)
		{
			str[i] = 0;
			newstr = ft_strdup(str);
			free(str);
		}
		i++;
	}
	return (newstr);
}