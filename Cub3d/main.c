#include "cub3d.h"

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
    cub3d->mlx_win = mlx_new_window(cub3d->mlx, 500,500 , "Cub3d");
    img->mlx_win = cub3d->mlx_win;
	mlx_hook(img->mlx_win, 2, 1L << 0, pushbutton, &img->mlx);
	mlx_hook(img->mlx_win, 17, (0L), pushbutton, img);
    mlx_loop(cub3d->mlx);
    free(img->map);
    free(img);
}