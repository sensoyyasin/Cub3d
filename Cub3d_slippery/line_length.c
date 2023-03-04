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
	//printf("y:%d, x:%d\n", y, x);
	//printf("calc:%d\n", (img->pixel * y + i) * img->max_map_width * img->pixel + (img->pixel * x) + j);
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
    int (i) = -2;
    int (j) = -2;
	while (i < img->pixel / 4)
	{
		j = -2;
		while (j < img->pixel / 4)
		{
			if ((j != 1 || i != 1) && (j != -1 || i != -1))
			{
				mlx_pixel_put(img->mlx, img->mlx_win, img->p_x * img->pixel + j, img->p_y * img->pixel + i, 0x00de5046);
			}
			else if (j != 0 || i != 0)
			{
				mlx_pixel_put(img->mlx, img->mlx_win, img->p_x * img->pixel + j, img->p_y * img->pixel + i, 0x000a0c0f);
			}
			else
				mlx_pixel_put(img->mlx, img->mlx_win, img->p_x * img->pixel, img->p_y * img->pixel, RED);
			j++;
		}
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
	int (ad) = 0;
	int (i) = -1;
	img->img = mlx_new_image(img->mlx, img->max_map_width * img->pixel, img->max_map_height * img->pixel);
	img->addr = (int*)mlx_get_data_addr(img->img, &ad, &ad, &ad);
	while (++i < img->max_map_width * img->pixel * img->max_map_height * img->pixel)
		img->addr[i] = 0xFF000000; // img->addr[i] = MAGENTA;
	putpixel(img);
	mlx_put_image_to_window(img->mlx, img->mlx_win, img->img, 0, 0);
	my_mlx_pixel_put2(img);
	printf("player x: %f, player y: %f\n", img->p_x, img->p_y);
	return (1);
}