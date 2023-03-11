#include "cub3d.h"

int line_length(t_cub3d *cub3dptr)
{
    int fdmap;
    char c;
    //char *str;
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

// void    my_mlx_pixe_put_angle(t_cub3d *img)
// {
//     int i = 0;
//     int j = 0;

//     while (i < img->pixel * 5)
// 	{
// 		j = 0;
// 		while (j < img->pixel * 5)
// 		{
//             if (i == j)
// 		        mlx_pixel_put(img->mlx, img->mlx_win, (img->p_x * img->pixel) + (img->angle_x * j), (img->p_y * img->pixel) - (img->angle_y * i), 0);
// 			j++;
// 		}
// 		i++;
// 	}
// }

void    my_mlx_pixe_put_angle(t_cub3d *img)
{
    int i = 0;

    while (i < img->pixel * 3)
	{
		mlx_pixel_put(img->mlx, img->mlx_win, (img->p_x * img->pixel) + (img->angle_x * i), (img->p_y * img->pixel) - (img->angle_y * i), 0);
		i++;
	}
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
    keycheckforloop(img);
	mlx_clear_window(img->mlx, img->mlx_win);
	mlx_put_image_to_window(img->mlx, img->mlx_win, img->img, 0, 0);
    my_mlx_pixe_put_angle(img);
	my_mlx_pixel_put2(img);
    drawRays3D(img);

    //--->for log file.
    // int fd;
    // fd = open("log", O_CREAT | O_TRUNC | O_WRONLY);
	// dprintf(fd, "player x: %f, player y: %f\n", img->p_x, img->p_y); //data-printf
    // close(fd);
	return (1);
}