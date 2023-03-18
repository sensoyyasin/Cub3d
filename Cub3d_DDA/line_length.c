#include "cub3d.h"

int line_length(t_cub3d *cub3dptr)
{
    int fdmap;
    char c;
    int i;

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

int column_length(t_cub3d *cub3dptr)
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
void my_mlx_pixel_put(t_cub3d *img, int x, int y, int color)
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
void my_mlx_pixel_put2(t_cub3d *img)
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
void pixel_to_player_image_address(t_cub3d *img, int x, int y, int color)
{
	img->addr_player[(y * img->pixel * img->max_map_width) + x] = color;
}

// ->mlx_pixel_put yerine image bastırmaya calistim burada.
// void my_mlx3_pixel_put_image(t_cub3d *img, int x, int y, int color)
// {
//     unsigned int *dst;

//     dst = (unsigned int *)(img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8)));
//     *dst = color;
// }

/* rays to screen */
void	my_mlx_pixe_put_angle(t_cub3d *img)
{
	int i = 0;
	double j = 0;
	double newp_x;
	double newp_y;
	double inc = ((double)ANGLE_CAMERA/(double)WINDOW_WIDTH);
	int counter = 0;//sil
	int (k) = -1;


	int (l) = 0;
	while (l < WINDOW_HEIGHT * WINDOW_WIDTH / 2)
			img->addr_game[l++] = img->c_final;
	while (l < WINDOW_HEIGHT * WINDOW_WIDTH)
			img->addr_game[l++] = img->f_final;
	
	//printf("inc : %f\n", inc); 
	//printf("j : %f\n",j); -> -30 degree

	while (++k < img->max_map_width * img->pixel * img->max_map_height * img->pixel)
		img->addr_ray[k] = 0xFF000000;//player transparent
	
	while (j < (double)ANGLE_CAMERA) // 30'dan - 30 'a kadar dönmüyor çünkü while - ye dönmüyor.
	{
		i = 0;
		while (1)
		{
			newp_x = ((img->p_x * img->pixel) + (cos((img->angle + 30 * DR) - (j * DR)) * i));
			newp_y = ((img->p_y * img->pixel) - (sin((img->angle + 30 * DR) - (j * DR)) * i));
			if (img->map[(int)(newp_y / img->pixel)][(int)(newp_x / img->pixel)] == '0')
			{
				pixel_to_ray_image_address(img, newp_x, newp_y, GREEN);
				//mlx_pixel_put(img->mlx, img->mlx_win, newp_x, newp_y, GREEN);
			}
			else
			{
				// double d = distance(img->p_x,img->p_y, newp_x,newp_y); //Player ve rayin koordinatlari.
				//draw3DWalls(img, i, counter);
				break;
			}
			i++;
		}
		j += inc;
		counter++;//sil
	}
	//mlx_put_image_to_window(img->mlx, img->mlx_win, img->img_ray, 0, 0);
	//printf("counter:%d\n", counter);
}

/* ray pixel to map address and player image to window */
void pixel_to_ray_image_address(t_cub3d *img, int x, int y, int color)
{
	img->addr_ray[(y * img->pixel * img->max_map_width) + x] = color;
}

void	draw3DWalls(t_cub3d *img, int i, int counter)
{
	while (WINDOW_HEIGHT - i)
	{
		img->addr_game[(WINDOW_HEIGHT - i)] = 0x00FF5733;
	}
}

// void draw3DWalls(t_cub3d *img, int i, int j, double distance_to_wall)
// {
// 	(void)distance_to_wall;
// 	//int k1 = (img->max_map_width * img->max_map_height / 2) + distance_to_wall;
// 	//int k2 = (img->max_map_width * img->max_map_height / 2) - distance_to_wall;

// 	mlx_pixel_put(img->mlx, img->mlx_win, i, j, RED);
// 	return ;
// }

double	distance(double x1, double y1, double x2, double y2)
{
	return (sqrt(((x2 - x1) * (x2 - x1)) + ((y2 - y1) * (y2 - y1))));
}

/* map image for each 1 and 0 char */
void putpixel(t_cub3d *cub3dptr)
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
int putimage(t_cub3d *img)
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

    //drawRays3D(img);
    //--->for log file.
    // int fd;
    // fd = open("log", O_CREAT | O_TRUNC | O_WRONLY);
	// dprintf(fd, "player x: %f, player y: %f\n", img->p_x, img->p_y); //data-printf
    // close(fd);
	return (1);
}