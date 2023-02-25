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

// void img_draw(t_cub3d *cub3dptr, void  *image, int x, int y)
// {
//     mlx_put_image_to_window(cub3dptr->mlx,
//         cub3dptr->mlx_win, image, x, y);
// }

// typedef struct	s_data
// {
// 	void	*img;
// 	char	*addr;
// 	int		bits_per_pixel;
// 	int		line_length;
// 	int		endian;
// }				t_data;

void putimage(t_cub3d *cub3dptr)
{
    int x;
    int y;

    x = 0;
    while (cub3dptr->map[x])
    {
        y = 0;
        while (cub3dptr->map[x][y])
        {
            // if (cub3dptr->map[x][y] == '1')
            //     my_mlx_pixel_put(&cub3dptr->img, x,y, 0x00FF0000);
            // else if (cub3dptr->map[x][y] == '0')
            //     my_mlx_pixel_put(&cub3dptr->img, x,y, 0x00FF0000);
            y++;
        }
        x++;
    }
}