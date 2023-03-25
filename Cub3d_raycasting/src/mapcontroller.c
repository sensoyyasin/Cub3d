/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapcontroller.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtemel <mtemel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 12:21:35 by ysensoy           #+#    #+#             */
/*   Updated: 2023/03/25 13:42:46 by mtemel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/cub3d.h"

void	isargtrue(t_cub3d *cub3dptr)
{
	int	len;

	len = ft_strlen2(cub3dptr->map_input[1]);
	if (cub3dptr->map_input[1][len - 1] != 'b' &&
		cub3dptr->map_input[1][len - 2] != 'u' &&
		cub3dptr->map_input[1][len - 3] != 'c' &&
		cub3dptr->map_input[1][len - 4] != '.')
	{
		write(2, "\033[1;31mWrong map format!\n\033[0m", 30);
		exit(1);
	}
}

void	mapcheck(t_cub3d *cub3dptr)
{
	int		fd_map;
	int		uz_y;
	char	*line;
	int		i;

	uz_y = -1;
	i = 0;
	fd_map = open(cub3dptr->map_input[1], O_RDONLY);
	if (fd_map < 0)
		exit_func2("\033[1;31mFile could not be opened!\n\033[0m");
	cub3dptr->map = malloc((sizeof(char *)) * 1024);
	while (++uz_y <= line_length(cub3dptr) && (line = get_next_line(fd_map)))
	{
		if (!cub3dptr->texture_bool)
			mapcheck2(line, cub3dptr);
		else if (!cub3dptr->map_bool
			&& cub3dptr->texture_bool && line[0] != '\n')
		{
			cub3dptr->map[i] = ft_strdup(line);
			write(1, cub3dptr->map[i], ft_strlen(cub3dptr->map[i]));
			i++;
		}
		free(line);
	}
	mapcontroller2(cub3dptr, i);
}

void	mapcheck2(char *words, t_cub3d *img)
{
	int		fd;
	int		i;

	i = 0;
	img->split = ft_split(words, ' ');
	if (!strcmp(img->split[0], "NO") || !strcmp(img->split[0], "SO")
		|| !strcmp(img->split[0], "WE") || !strcmp(img->split[0], "EA"))
	{
		img->split[1] = clear_endstr(img->split[1]);
		fd = open(img->split[1], O_RDONLY);
		if (fd < 0 || isargtrue2(img->split[1]))
			exit_split_func(img->split, img);
		split_comp(img->split, img);
	}
	else if (!strcmp(img->split[0], "F") || !strcmp(img->split[0], "C"))
	{
		ft_color(img);
		double_free_split(img->split, img->ut_color);
	}
	else
	{
		free(img->split[0]);
		free(img->split);
	}
	texture_check(img);
}

void	mapcheck3(char *words, t_cub3d *img)
{
	int (j) = 0;
	while (words[j] && words[j] != '\n')
	{
		if (words[j] != '1' && words[j] != '0' && words[j] != 'N'
			&& words[j] != 'S' && words[j] != 'E' && words[j] != 'W'
			&& words[j] != '\n' && words[j] != ' ' && words[j] != 32)
		{
			exit_func("hatali bir yer var\n", img);
		}
		else
		{
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
			exit_func("\nW, S, E, or N not occured once\n", img);
		j++;
	}
}

void	realmapcheck(int i, t_cub3d *img)
{
	int (j) = 0;
	while (img->map[i])
	{
		j = -1;
		while (img->map[i][++j])
		{
			if ((img->map[i][j] == 'N' || img->map[i][j] == 'S'
				|| img->map[i][j] == 'W' || img->map[i][j] == 'E')
				&& (img->map[i][j - 1] <= 32 || img->map[i][j + 1] <= 32))
				exit_func("Player yanı hatası\n", img);
			if (img->map[i][j] == ' ' && img->map[i][j] == '\t')
				j++;
			else if (img->map[i][j] == '0' && (!img->map[i - 1]
					|| !img->map[i - 1][j] || img->map[i - 1][j] <= 32))
				exit_func("Ilk satir hatası\n", img);
			else if (img->map[i][0] != '1' && img->map[i][0] > 32)
				exit_func("Ilk sutun 0 hatasi\n", img);
			else if (img->map[i][j + 1] == '\n' && img->map[i][j] == '0')
				exit_func("Son sutun 0 hatasi\n", img);
			else if (img->map[i][j] == '0' && (i == img->max_map_height - 1
					|| (img->map[i + 1][j] && img->map[i + 1][j] <= 32)))
				exit_func("Son satir 0 hatasi\n", img);
		}
		i++;
	}
}
