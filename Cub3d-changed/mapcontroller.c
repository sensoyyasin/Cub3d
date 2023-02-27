#include "cub3d.h"

void isargtrue(t_cub3d *cub3dptr)
{
    int len;

    len = ft_strlen2(cub3dptr->map_input[1]);
    if (cub3dptr->map_input[1][len - 1] != 'b' &&
        cub3dptr->map_input[1][len - 2] != 'u' &&
        cub3dptr->map_input[1][len - 3] != 'c' &&
        cub3dptr->map_input[1][len - 4] != '.')
        {
		    exit_func("\033[1;31mWrong map format!\n\033[0m", cub3dptr);
        }
}

void mapcheck(t_cub3d *cub3dptr)
{
    int fd_map;
    int uz_y;
    
    uz_y = -1;
    fd_map = open(cub3dptr->map_input[1], O_RDONLY);
    if (fd_map < 0)
		exit_func("\033[1;31mFile could not be opened!\n\033[0m", cub3dptr);
    cub3dptr->map = malloc((sizeof(char *)) * 1024);
    while (++uz_y <= line_length(cub3dptr))
    {
		cub3dptr->map[uz_y] = get_next_line(fd_map);
		if(!cub3dptr->texture_bool)
		{
			mapcheck2(cub3dptr->map[uz_y], cub3dptr);
			printf("texture check uz_y:%d\n", uz_y);
		}
		else if (!cub3dptr->map_bool && cub3dptr->texture_bool)
		{
			mapcheck3(cub3dptr->map[uz_y], cub3dptr);
		}
		free(cub3dptr->map[uz_y]);
    }
	printf("i:%d\n", uz_y);
	printf("Texture check uz_y2: %d\n", uz_y);
    close(fd_map);
}

void mapcheck2(char *words, t_cub3d *img)
{
	int fd;
	char **split;
	char **color;
	int (i) = 0;

	split = ft_split(words, ' ');
	if(!strcmp(split[0], "NO") || !strcmp(split[0], "SO")
		|| !strcmp(split[0], "WE") || !strcmp(split[0], "EA"))
	{
		split[1] = clear_endstr(split[1]);
		if ((fd = open(split[1], O_RDONLY)) < 0) //./map.cub 'u acamadigi icin hata.
			exit_split_func(split, img);
		split_comp(split, img);
	}
	else if(!strcmp(split[0], "F") || !strcmp(split[0], "C"))
	{
		color = ft_split(split[1], ',');
		while (i < 3)
		{
			if (!color[i] || !is_number(color[i]) || ft_atoi(color[i]) > 255 || ft_atoi(color[i]) < 0)
				exit_double_split_func(split, color, img);
			else if (strcmp(split[0], "F") == 0)
			{
				img->f_color[i] = ft_atoi(color[i]);
				if (i == 2)
					img->f = 1;
			}
			else if (strcmp(split[0], "C") == 0)
			{
				img->c_color[i] = ft_atoi(color[i]);
				if (i == 2)
					img->c = 1;
			}
			i++;
		}
		double_free_split(split, color);
	}
	if (img->no == 1 && img->so == 1 && img->we == 1 && img->ea == 1 && img->f == 1 && img->c == 1)
		img->texture_bool = 1;
}

void mapcheck3(char *words, t_cub3d *img) {

    int i = 0;
    int j = 0;

    while (words[j])
	{
        if (words[j] != '1' && words[j] != '0' && words[j] != 'N'
            && words[j] != 'S' && words[j] != 'E' && words[j] != 'W'
            && words[j] != '\n' && words[j] != ' ' && words[j] != 32) {
            free_all(img);
            printf("%c : Hatali bir yer var.\n", words[j]);
            exit(1);
        }
        else {
            if (words[j] == 'N')
                img->n_timer++;
            else if (words[j] == 'S')
                img->s_timer++;
            else if (words[j] == 'E')
                img->e_timer++;
            else if (words[j] == 'W')
                img->w_timer++;
        }
		if (img->n_timer + img->s_timer + img->e_timer + img->w_timer > 1)
		{
			printf("\033[1;36mntimer: %d\n", img->n_timer);
			printf("stimer: %d\n", img->s_timer);
			printf("etimer: %d\n", img->e_timer);
			printf("wtimer: %d\033[0m\n", img->w_timer);
			exit_func("W, S, E, or N not occured once\n", img);
		}
		printf("%c",words[j]);
         j++;
    }
    if ((img->w_timer == 1 || img->s_timer == 1 || img->e_timer == 1 || img->n_timer == 1) && !words[i]) {
        img->map_bool = 1;
    }
}