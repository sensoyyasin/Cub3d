#include "cub3d.h"

void check_all(t_cub3d *img)
{
	isargtrue(img);
	mapcheck(img);
}

void free_all(t_cub3d *img, t_cub3d *cub3d)
{
	free(cub3d);
    free(img->map);
    free(img);
}

int main(int argc, char **argv)
{
    t_cub3d *img;
    t_cub3d *cub3d;

    if (argc != 2)
		return (printf("\033[1;31mBad argument!\n\033[0m"));
    img = (t_cub3d *)malloc(sizeof(t_cub3d));
    cub3d = (t_cub3d *)malloc(sizeof(t_cub3d));
    img->map_input = argv;
	check_all(img);
    cub3d->mlx = mlx_init();
    img->mlx = cub3d->mlx;
    cub3d->mlx_win = mlx_new_window(cub3d->mlx, 750, 750 ,"Cub3d");
    putimage(img);
    img->mlx_win = cub3d->mlx_win;
	mlx_hook(img->mlx_win, 2, 1L << 0, pushbutton, &img->mlx);
	mlx_hook(img->mlx_win, 17, (0L), pushbutton, img);
    mlx_loop(cub3d->mlx);
	free_all(img, cub3d);
}
