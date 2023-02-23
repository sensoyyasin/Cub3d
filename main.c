#include <unistd.h>
#include <stdio.h>
#include "minilibx/mlx.h"

typedef struct	s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int main()
{
    void *mlx;
    void *mlx_win;
    t_data img;
    int i = 0;
    int j = 0;

    mlx = mlx_init();
    mlx_win = mlx_new_window(mlx, 1000, 1000, "Cub3d");
    img.img = mlx_new_image(mlx, 1000, 1000);
    img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
        &img.endian);
    int a = 0;
    while (a < 1000)
    {
        while (i < 999)
        {
            int aa = i * j / 3;
            j = 0;
            while (j < 999)
            {
                int bb = j / 2;
                if ((500 - i)*(500 - i) + (500 - j)*(500 - j) <= 10000)
                    my_mlx_pixel_put(&img, i,j,  (i * j % 5 ) ? (((aa * bb * i * j) % 255 << 24) | 255 << 16) : 255 << 16);
                j++;
            }
            my_mlx_pixel_put(&img, i,j, 0x00FF0000);
            i++;
            usleep(50);
        }
            mlx_put_image_to_window(mlx,mlx_win, img.img, 0,0);
    //mlx_hook(mlx_win, 2, 1l << 0, closex, &mlx);
    mlx_loop(mlx);
    }

    //write(1, "The code\n",9);
    return (0);
}