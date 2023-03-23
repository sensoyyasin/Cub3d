/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_length.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysensoy <ysensoy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 21:37:42 by yasinsensoy       #+#    #+#             */
/*   Updated: 2023/03/23 12:12:39 by ysensoy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	line_length(t_cub3d *cub3dptr)
{
	int		fdmap;
	char	c;
	int		i;

	i = 0;
	fdmap = open(cub3dptr->map_input[1], O_RDONLY);
	while (read(fdmap, &c, 1) >= 1)
	{
		if (ft_strchr(&c, '\n'))
			i++;
	}
	close(fdmap);
	return (i);
}

int	column_length(t_cub3d *cub3dptr)
{
	int fdmap;
	char *line;
	int i;

	fdmap = open(cub3dptr->map_input[1], O_RDONLY);
	line = get_next_line(fdmap);
	close(fdmap);
	i = ft_strlen2(line - 1);
	free(line);
	return (i);
}

/* map image address filling */
void	my_mlx_pixel_put(t_cub3d *img, int x, int y, int color)
{
	int (i) = 0;
	int (j) = 0;
	while (i < img->pixel)
	{
		j = 0;
		while (j < img->pixel)
		{
			img->addr_map[(img->pixel * y + i) * img->max_map_width * img->pixel + (img->pixel * x) + j] = color;
			j++;
		}
		i++;
	}
}

/* player to screen */
void	my_mlx_pixel_put2(t_cub3d *img)
{
	int (i) = - img->pixel / 4 + 1;
	int (j) = - img->pixel / 4 + 1;
	int (k) = -1;
	while (++k < img->max_map_width * img->pixel * img->max_map_height * img->pixel)
		img->addr_player[k] = 0xFF000000;//player transparent
	while (++i < img->pixel / 4 - 2)
	{
		j = - img->pixel / 4 + 1;
		while (++j < img->pixel / 4 - 2)
			pixel_to_player_image_address(img, img->p_x * img->pixel + j, img->p_y * img->pixel + i, RED);
			//mlx_pixel_put(img->mlx, img->mlx_win, img->p_x * img->pixel + j, img->p_y * img->pixel + i, RED);
	}
	//mlx_put_image_to_window(img->mlx, img->mlx_win, img->img_player, 0, 0);
}

/* player pixel to map address and player image to window */
void	pixel_to_player_image_address(t_cub3d *img, int x, int y, int color)
{
	img->addr_player[(y * img->pixel * img->max_map_width) + x] = color;
}

/* rays to screen */
void	my_mlx_pixe_put_angle(t_cub3d *img)
{
	double (j) = -(double)ANGLE_CAMERA / 2.0;
	int ray_counter = 0;

	fill_addr(img);
	//Ray casting --> Starting... i've done ray_casting file.
	while (j <= (ANGLE_CAMERA / 2.0))
	{
		raycasting(img, (img->angle * (180.0 / PI)) + j, ray_counter);
		j += (ANGLE_CAMERA / 2.0) / (WINDOW_WIDTH / 2.0);
		ray_counter++;
	}
}

void	fill_addr(t_cub3d *img)
{
	int (k) = -1;
	int (l) = 0;
	while (l < WINDOW_HEIGHT * WINDOW_WIDTH / 2.0)
			img->addr_game[l++] = img->c_final;
	while (l < WINDOW_HEIGHT * WINDOW_WIDTH)
			img->addr_game[l++] = img->f_final;

	while (++k < img->max_map_width * img->pixel * img->max_map_height * img->pixel)
		img->addr_ray[k] = 0xFF000000;//player transparent
}

/* ray pixel to map address and player image to window */
void pixel_to_ray_image_address(t_cub3d *img, int x, int y, int color)
{
	img->addr_ray[(y * img->pixel * img->max_map_width) + x] = color;
}

void	draw3DWalls(t_cub3d *img, double i, int counter, int dir)
{
	(void)dir;
	int (j) = 0;
	while (j < WINDOW_HEIGHT / i * 5 && ((WINDOW_HEIGHT / 2) * WINDOW_WIDTH + counter) - (WINDOW_WIDTH * j) >= 0
			&& ((WINDOW_HEIGHT / 2) * WINDOW_WIDTH + counter) + (WINDOW_WIDTH * j) < WINDOW_WIDTH * WINDOW_HEIGHT)
	{
		img->addr_game[((WINDOW_HEIGHT / 2) * WINDOW_WIDTH + counter) + (WINDOW_WIDTH * j)] = 0x6000FFFF;
		img->addr_game[((WINDOW_HEIGHT / 2) * WINDOW_WIDTH + counter) - (WINDOW_WIDTH * j)] = 0x6000FFFF;
		j++;
	}
}

/* map image for each 1 and 0 char */
void	putpixel(t_cub3d *cub3dptr)
{
	int x;
	int y;

	y = 0;
	while (cub3dptr->map[y])
	{
		x = 0;
		while (cub3dptr->map[y][x])
		{
			if (cub3dptr->map[y][x] == '1')
				my_mlx_pixel_put(cub3dptr, x, y, BLUE);
			else if (cub3dptr->map[y][x] == '0')
				my_mlx_pixel_put(cub3dptr, x, y, WHITE);
			x++;
		}
		y++;
	}
}

/* the function works each MAIN loop */
int	putimage(t_cub3d *img)
{
	mlx_clear_window(img->mlx, img->mlx_win);
	keycheckforloop(img);
	my_mlx_pixe_put_angle(img);
	my_mlx_pixel_put2(img);
	mlx_put_image_to_window(img->mlx, img->mlx_win, img->img_game, 0, 0);
	if (img->check->tab_check)
	{
		mlx_put_image_to_window(img->mlx, img->mlx_win, img->img_map, 0, 0);
		mlx_put_image_to_window(img->mlx, img->mlx_win, img->img_ray, 0, 0);
		mlx_put_image_to_window(img->mlx, img->mlx_win, img->img_player, 0, 0);
	}
	return (1);
}
