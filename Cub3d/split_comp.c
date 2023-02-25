#include "cub3d.h"

void free_split(char **split)
{
	int (i) = 0;
	while (split[i])
		free(split[i++]);
	free(split);
}

void split_comp(char **split, t_cub3d *img)
{
	if(strcmp(split[0], "NO") == 0)
	{
		img->no_path = ft_strdup(split[1]);
		free_split(split);
	}
	else if(strcmp(split[0], "SO") == 0)
	{
		img->so_path = ft_strdup(split[1]);
		free_split(split);
	}
	else if(strcmp(split[0], "WE") == 0)
	{
		img->we_path = ft_strdup(split[1]);
		free_split(split);
	}
	else if(strcmp(split[0], "EA") == 0)
	{
		img->ea_path = ft_strdup(split[1]);
		free_split(split);
	}
}