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

void my_mlx_pixel_put(t_cub3d *img, int x, int y, int color)
{
    int (i) = 0;
    int (j) = 0;
	while (i < img->pixel)
	{
		j = 0;
		while (j < img->pixel)
		{
			img->addr[(img->pixel * y + i) * img->max_map_width * img->pixel + (img->pixel * x) + j] = color;
			j++;
		}
		i++;
	}
}

void my_mlx_pixel_put2(t_cub3d *img)
{
    int (i) = - img->pixel / 4 + 1;
    int (j) = - img->pixel / 4 + 1;
	while (++i < img->pixel / 4 - 2)
	{
		j = - img->pixel / 4 + 1;
		while (++j < img->pixel / 4 - 2)
			mlx_pixel_put(img->mlx, img->mlx_win, img->p_x * img->pixel + j, img->p_y * img->pixel + i, RED);
	}
}

// ->mlx_pixel_put yerine image bastırmaya calistim burada.
// void my_mlx3_pixel_put_image(t_cub3d *img, int x, int y, int color)
// {
//     unsigned int *dst;

//     dst = (unsigned int *)(img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8)));
//     *dst = color;
// }

void    my_mlx_pixe_put_angle(t_cub3d *img)
{
	int i = 0;
	double j = 0;
	double newp_x;
	double newp_y;
	double inc = ((double)ANGLE_CAMERA/(double)WINDOW_WIDTH);

	printf("inc : %f\n", inc); 
	//printf("j : %f\n",j); -> -30 degree
	while (j  < (double)ANGLE_CAMERA) // 30'dan - 30 'a kadar dönmüyor çünkü while - ye dönmüyor.
	{
		i = 0;
		while (1)
		{
			newp_x = ((img->p_x * img->pixel) + (cos((img->angle + 30 * DR) - (j * DR)) * i));
			newp_y = ((img->p_y * img->pixel) - (sin((img->angle + 30 * DR) - (j * DR)) * i));
			if (img->map[(int)(newp_y / img->pixel)][(int)(newp_x / img->pixel)] == '0')
			{
				//my_mlx3_pixel_put_image(img->mlx, newp_x, newp_y, GREEN);
				mlx_pixel_put(img->mlx, img->mlx_win, newp_x, newp_y, GREEN);
			}
			else
			{
				// double d = distance(img->p_x,img->p_y, newp_x,newp_y); //Player ve rayin koordinatlari.
				// draw3DWalls(img, i, j, d);
				break;
			}
			i++;
		}
		j++;
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
                my_mlx_pixel_put(cub3dptr, x, y, CYAN);
            else if (cub3dptr->map[y][x] == '0')
                my_mlx_pixel_put(cub3dptr, x, y, WHITE);
            x++;
        }
        y++;
    }
}

int putimage(t_cub3d *img)
{
	mlx_clear_window(img->mlx, img->mlx_win);
    keycheckforloop(img);
	mlx_put_image_to_window(img->mlx, img->mlx_win, img->img, 0, 0);
	if (img->check->tab_check)
	{
    	my_mlx_pixe_put_angle(img);
		my_mlx_pixel_put2(img);
	}

    //drawRays3D(img);
    //--->for log file.
    // int fd;
    // fd = open("log", O_CREAT | O_TRUNC | O_WRONLY);
	// dprintf(fd, "player x: %f, player y: %f\n", img->p_x, img->p_y); //data-printf
    // close(fd);
	return (1);
}