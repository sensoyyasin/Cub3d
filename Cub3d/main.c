#include "cub3d.h"

void check_all(t_cub3d *img)
{
	isargtrue(img);
	mapcheck(img);
	 printf("img->texture_bool: %d, img->map_bool: %d\n", img->texture_bool, img->map_bool);
  	if (!img->texture_bool || !img->map_bool)
        exit_func("\033[1;31mMap or texture error\033[0m", img);
}

void free_all(t_cub3d *img)
{
    free(img->map);
    free(img);
}

void initializer(t_cub3d *img)
{
	img->no = 0;
	img->so = 0;
	img->we = 0;
	img->ea = 0;
	img->n_timer = 0;
	img->s_timer = 0;
	img->e_timer = 0;
	img->w_timer = 0;
	img->f = 0;
	img->c = 0;
	img->texture_bool = 0;
	img->map_bool = 0;
}

int main(int argc, char **argv)
{
    t_cub3d *img;

    if (argc != 2)
		return (printf("\033[1;31mBad argument!\n\033[0m"));
    img = (t_cub3d *)malloc(sizeof(t_cub3d));
    img->map_input = argv;
	initializer(img);
	check_all(img);
    img->mlx = mlx_init();
    img->mlx_win = mlx_new_window(img->mlx, 750, 750 ,"Cub3d");
    //putimage(img);
	mlx_hook(img->mlx_win, 2, 1L << 0, pushbutton, &img->mlx);
	mlx_hook(img->mlx_win, 17, (0L), pushbutton, img);
    mlx_loop(img->mlx);
	free_all(img);
}
