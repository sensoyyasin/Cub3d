#include "cub3d.h"

void mapcheck(t_cub3d *cub3dptr)
{
    int fd_map;
    int uz_y;
    
    uz_y = -1;
    fd_map = open(cub3dptr->map_input[1], O_RDONLY);
    if (fd_map < 0)
        exit(0);
    cub3dptr->y_kord = 0;
    cub3dptr->map = malloc((sizeof(char *)) * 1024);
    while (++uz_y < line_length(cub3dptr))
    {
        cub3dptr->map[uz_y] = get_next_line(fd_map);
        //mapcheck2(cub3dptr->map[uz_y]);
        printf("%s",cub3dptr->map[uz_y]);
    }
    close(fd_map);
}

int main(int argc, char **argv)
{
    if (argc != 2)
        return (write(1, "Number of arguman is false\n", 27));
    t_cub3d *img;
    t_cub3d *cub3d;

    img = (t_cub3d *)malloc(sizeof(t_cub3d));
    cub3d = (t_cub3d *)malloc(sizeof(t_cub3d));
    cub3d->mlx = mlx_init();
    img->mlx = cub3d->mlx;
    img->map_input = argv;
    isargtrue(img);
    cub3d->mlx_win = mlx_new_window(cub3d->mlx, 750, 750 ,"Cub3d");
    mapcheck(img);
    putimage(img);
    img->mlx_win = cub3d->mlx_win;
	mlx_hook(img->mlx_win, 2, 1L << 0, pushbutton, &img->mlx);
	mlx_hook(img->mlx_win, 17, (0L), pushbutton, img);
    mlx_loop(cub3d->mlx);
    free(cub3d);
    free(img->map);
    free(img);
}
