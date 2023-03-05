#include "cub3d.h"

void check_all(t_cub3d *img)
{
	isargtrue(img);
	mapcheck(img);
	if (!img->texture_bool || !img->map_bool)
        exit_func("\033[1;31mMap or texture error\033[0m", img);
	player(img);
}

void free_all(t_cub3d *img)
{
    free(img->map);
    free(img);
}

void initializer(t_cub3d *img)
{
	img->check->w_check = false;
	img->check->a_check = false;
	img->check->s_check = false;
	img->check->d_check = false;
	img->check->l_check = false;
	img->check->r_check = false;
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
	img->speed_pixel = 4;
	img->pixel = 32;
	img->max_map_width = 0;
	img->max_map_height = 0;
	img->speed = (double)img->speed_pixel / (double)img->pixel;
}

// void	start_window(t_cub3d *img)
// {
// 	int (ad) = 0;
// 	initializer(img);
// 	check_all(img);
// 	img->mlx = mlx_init();
// 	img->mlx_win = mlx_new_window(img->mlx, 1080, 720,"Cub3d");
// 	player(img);
// 	img->img = mlx_new_image(img->mlx, img->max_map_width * img->pixel, img->max_map_height * img->pixel);
// 	img->addr = (int*)mlx_get_data_addr(img->img, &ad, &ad, &ad);
// 	int (i) = -1;
// 	while (++i < img->max_map_width * img->pixel * img->max_map_height * img->pixel)
// 		img->addr[i] = 0xFF000000;
// 	mlx_put_image_to_window(img->mlx, img->mlx_win, img->img, 0, 0); //dogru.
// }

void	map_addr(t_cub3d *img)
{
	int (ad) = 0;
	int (i) = -1;
	img->img = mlx_new_image(img->mlx, img->max_map_width * img->pixel, img->max_map_height * img->pixel);
	img->addr = (int*)mlx_get_data_addr(img->img, &ad, &ad, &ad);
	while (++i < img->max_map_width * img->pixel * img->max_map_height * img->pixel)
		img->addr[i] = 0xFF000000;
	putpixel(img);
}

int main(int argc, char **argv)
{
	t_cub3d *img;

	if (argc != 2)
		return (printf("\033[1;31mBad argument!\n\033[0m"));
	img = (t_cub3d *)malloc(sizeof(t_cub3d));
	img->check = (t_check *)malloc(sizeof(t_check));
	img->map_input = argv;
	initializer(img);
	check_all(img);
	img->mlx = mlx_init();
	img->mlx_win = mlx_new_window(img->mlx, 1080, 720,"Cub3d");
	map_addr(img);
	//start_window(img);
	//Bu iki çağrı arasındaki fark, olayların türüdür. İlk çağrı, bir klavye tuşuna basıldığında çalışacakken, ikinci çağrı klavye tuşunun serbest bırakılması durumunda çalışacaktır.
	mlx_hook(img->mlx_win, 2, 1L << 0, keychecker, &img->mlx);
	mlx_hook(img->mlx_win, 17, (0L), pushbutton, img); //kapatmak icin.
	mlx_hook(img->mlx_win, 3, 1L << 0, keychecker2, &img->mlx);
	mlx_loop_hook(img->mlx, putimage, img);
	mlx_loop(img->mlx);
	//free_all(img);
}
