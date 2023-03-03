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
	//mlx_clear_window(img->mlx, img->mlx_win);
    while (i < img->pixel)
    {
        j = 0;
        while (j < img->pixel)
        {
            mlx_pixel_put(img->mlx, img->mlx_win, (x * img->pixel) + j, (y * img->pixel) + i, color);
            j++;
        }
        i++;
    }
	//while (i < img->pixel)
	//{
	//	j = 0;
	//	while (j < img->pixel)
	//	{
	//		img->addr[(y + i) * img->pixel * 11 + x + j] = color;
	//		j++;
	//	}
	//	i++;
	//}
}

void my_mlx_pixel_put2(t_cub3d *img, double x, double y, int color)
{
    //int (i) = 0;
    //int (j) = 0;
    
    //while (i < img->pixel)
    //{
    //    j = 0;
    //    while (j < img->pixel)
    //    {
    //        mlx_pixel_put(img->mlx, img->mlx_win, (x * img->pixel) + j, (y * img->pixel) + i, color);
    //        j++;
    //    }
    //    i++;
    //}
    mlx_pixel_put(img->mlx, img->mlx_win, (x * img->pixel), (y * img->pixel), color);
    // mlx_pixel_put(img->mlx, img->mlx_win, (x * img->pixel) + 1, (y * img->pixel), color);
    // mlx_pixel_put(img->mlx, img->mlx_win, (x * img->pixel) - 1, (y * img->pixel), color);
    // mlx_pixel_put(img->mlx, img->mlx_win, (x * img->pixel), (y * img->pixel) + 1, color);
    // mlx_pixel_put(img->mlx, img->mlx_win, (x * img->pixel), (y * img->pixel) - 1, color);
}

// void my_mlx_pixel_put3(t_cub3d *img, int x, int y, int color, char *str)
// {
//     int (i) = 0;
//     int (j) = 0;
//     double speed = img->speed_pixel / img->pixel; // 10 / 16
    
//     if (ft_strncmp(str, "-x", 2) == 0)
//     {
//         while (i < img->pixel)
//         {
//             j = 0;
//             while (j < img->pixel)
//             {
//                 mlx_pixel_put(img->mlx, img->mlx_win, (x * img->pixel) + j, (y * img->pixel) + i, color);
//                 j++;
//             }
//             i++;
//         }   
//     }
// }

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
	my_mlx_pixel_put2(cub3dptr, cub3dptr->p_x, cub3dptr->p_y, RED);
}

void putimage(t_cub3d *img)
{
	int (ad) = 0;
	int (i) = -1;
	img->img = mlx_new_image(img->mlx, img->max_map_width * img->pixel, img->max_map_height * img->pixel);
	img->addr = (int*)mlx_get_data_addr(img->img, &ad, &ad, &ad);
	while (++i < img->max_map_width * img->pixel * img->max_map_height * img->pixel)
		img->addr[i] = 0xFF000000;
	putpixel(img);
	mlx_put_image_to_window(img->mlx, img->mlx_win, img->img, 0, 0);
}