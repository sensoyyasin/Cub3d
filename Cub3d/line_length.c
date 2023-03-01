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
            mlx_pixel_put(img->mlx, img->mlx_win, (x * img->pixel) + j, (y * img->pixel) + i, color);
            j++;
        }
        i++;
    }
}

void my_mlx_pixel_put2(t_cub3d *img, int x, int y, int color)
{
    int (i) = 0;
    int (j) = 0;
    
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

void putimage(t_cub3d *cub3dptr)
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
                my_mlx_pixel_put(cub3dptr, x,y, WHITE);
            else if (cub3dptr->map[y][x] == 'N' || cub3dptr->map[y][x] == 'S' || cub3dptr->map[y][x] == 'E'
                || cub3dptr->map[y][x] == 'W')
                {
                    my_mlx_pixel_put(cub3dptr, x, y, WHITE);
                    my_mlx_pixel_put2(cub3dptr, x, y, RED);
                }
            x++;
        }
        y++;
    }
}