#include "cub3d.h"

int pushbutton(int keycode, t_cub3d *ptr)
{
    //en sonda cukur problemi
	player(ptr);
    if (keycode == ESC)
    {
        mlx_destroy_window(ptr->mlx, ptr->mlx_win);
        exit_func("\033[35m\nGame was closing\n", ptr);
    }
    else if (keycode == W)
        turnup(ptr);
    else if (keycode == A)
        turnleft(ptr);
    else if (keycode == S)
        turndown(ptr);
    else if (keycode == D)
        turnright(ptr);
    return (0);
}

void turnleft(t_cub3d *cub3d)
{
    if (cub3d->map[cub3d->y_kord][cub3d->x_kord - 1] == '0')
    {
        //mevcut oyuncu konumunu zemin rengi yap.
        my_mlx_pixel_put2(cub3d, cub3d->x_kord, cub3d->y_kord, WHITE);

        //Yeni oyuncu konumu yeşil olsun.
        my_mlx_pixel_put2(cub3d, cub3d->x_kord - 1, cub3d->y_kord, RED);

	    cub3d->map[cub3d->y_kord][cub3d->x_kord] = '0';
	    cub3d->map[cub3d->y_kord][cub3d->x_kord - 1] = 'N';
        cub3d->x_kord--;
    }
}

void turnright(t_cub3d *cub3d)
{
    if (cub3d->map[cub3d->y_kord][cub3d->x_kord + 1] == '0')
    {
        my_mlx_pixel_put2(cub3d, cub3d->x_kord, cub3d->y_kord, WHITE);
        my_mlx_pixel_put2(cub3d, cub3d->x_kord + 1, cub3d->y_kord, RED);
	    cub3d->map[cub3d->y_kord][cub3d->x_kord] = '0';
	    cub3d->map[cub3d->y_kord][cub3d->x_kord + 1] = 'N';
        cub3d->x_kord++;
    }
}

void turnup(t_cub3d *cub3d)
{
    if (cub3d->map[cub3d->y_kord - 1][cub3d->x_kord] == '0')
    {
        my_mlx_pixel_put2(cub3d, cub3d->x_kord, cub3d->y_kord, WHITE);
        my_mlx_pixel_put2(cub3d, cub3d->x_kord, cub3d->y_kord - 1, RED);
	    cub3d->map[cub3d->y_kord][cub3d->x_kord] = '0';
	    cub3d->map[cub3d->y_kord - 1][cub3d->x_kord] = 'N';
        cub3d->y_kord--;
    }
}

void turndown(t_cub3d *cub3d)
{
    if (cub3d->map[cub3d->y_kord + 1][cub3d->x_kord] == '0')
    {
        my_mlx_pixel_put2(cub3d, cub3d->x_kord, cub3d->y_kord, WHITE);
        my_mlx_pixel_put2(cub3d, cub3d->x_kord, cub3d->y_kord + 1, RED);
	    cub3d->map[cub3d->y_kord][cub3d->x_kord] = '0';
	    cub3d->map[cub3d->y_kord + 1][cub3d->x_kord] = 'N';
        cub3d->y_kord++;
    }
}

void player(t_cub3d *cub3dptr)
{
    cub3dptr->x_kord = 0;
    cub3dptr->y_kord = 0;

    while (cub3dptr->map[cub3dptr->y_kord][cub3dptr->x_kord])
	{
		cub3dptr->x_kord = 0;
		while (cub3dptr->map[cub3dptr->y_kord][cub3dptr->x_kord] != '\n')
		{
			if (cub3dptr->map[cub3dptr->y_kord][cub3dptr->x_kord] == 'N'
            || cub3dptr->map[cub3dptr->y_kord][cub3dptr->x_kord] == 'S'
            || cub3dptr->map[cub3dptr->y_kord][cub3dptr->x_kord] == 'E'
            || cub3dptr->map[cub3dptr->y_kord][cub3dptr->x_kord] == 'W')
            {
			    return ;
            }
            cub3dptr->x_kord++;
		}
		cub3dptr->y_kord++;
	}
}