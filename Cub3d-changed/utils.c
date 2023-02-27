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
			//free(str + ft_strlen(newstr));
			free(str);
		}
		i++;
	}
	return (newstr);
}

int is_number(char *str)
{
	int (i) = 0;
	if (!str)
		return (0);
	while(str[i])
	{
		if(str[i] > '9' && str[i] < '0')
			return (0);
		i++;
	}
	return (1);
}