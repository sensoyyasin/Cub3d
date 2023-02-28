#include "cub3d.h"

int pushbutton(int keycode, t_cub3d *ptr)
{
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

void player(t_cub3d *cub3dptr)
{
    int key;

    cub3dptr->x_kord = 0;
    cub3dptr->y_kord = 0;
    key = 1;
    while (cub3dptr->map[cub3dptr->y_kord][cub3dptr->x_kord] && key == 1)
	{
		cub3dptr->x_kord = 0;
		while (cub3dptr->map[cub3dptr->y_kord][cub3dptr->x_kord] != '\n'
			&& key == 1)
		{
			if (cub3dptr->map[cub3dptr->y_kord][cub3dptr->x_kord] == 'N'
            || cub3dptr->map[cub3dptr->y_kord][cub3dptr->x_kord] == 'S'
            || cub3dptr->map[cub3dptr->y_kord][cub3dptr->x_kord] == 'E'
            || cub3dptr->map[cub3dptr->y_kord][cub3dptr->x_kord] == 'W')
			key = 0;
			cub3dptr->x_kord++;
		}
		cub3dptr->y_kord++;
	}
}

void turnleft(t_cub3d *cub3d)
{
    player(cub3d);
    //printf("x_kord: %d\n y_kord: %d\n",cub3d->x_kord, cub3d->y_kord);
    if (cub3d->map[cub3d->y_kord - 1][cub3d->x_kord - 2] == '0')
    {
        //mevcut oyuncu konumunu zemin rengi yap.
        my_mlx_pixel_put(cub3d, cub3d->x_kord - 1, cub3d->y_kord - 1, WHITE);

        //Yeni oyuncu konumu yeşil olsun.
        my_mlx_pixel_put(cub3d, cub3d->x_kord - 2, cub3d->y_kord - 1, RED);

	    cub3d->map[cub3d->y_kord-1][cub3d->x_kord - 1] = '0';
	    cub3d->map[cub3d->y_kord-1][cub3d->x_kord - 2] = 'N';
        cub3d->x_kord--;
    }
}

void turnright(t_cub3d *cub3d)
{
    player(cub3d);
    if (cub3d->map[cub3d->y_kord - 1][cub3d->x_kord] == '0')
    {
        my_mlx_pixel_put(cub3d, cub3d->x_kord - 1, cub3d->y_kord - 1, WHITE);
        my_mlx_pixel_put(cub3d, cub3d->x_kord, cub3d->y_kord - 1, RED);
	    cub3d->map[cub3d->y_kord - 1][cub3d->x_kord - 1] = '0';
	    cub3d->map[cub3d->y_kord - 1][cub3d->x_kord] = 'N';
        cub3d->x_kord++;
    }
}

void turnup(t_cub3d *cub3d)
{
    player(cub3d);
    if (cub3d->map[cub3d->y_kord - 2][cub3d->x_kord - 1] == '0')
    {
        my_mlx_pixel_put(cub3d, cub3d->x_kord - 1, cub3d->y_kord - 1, WHITE);
        my_mlx_pixel_put(cub3d, cub3d->x_kord - 1, cub3d->y_kord - 2, RED);
	    cub3d->map[cub3d->y_kord-1][cub3d->x_kord - 1] = '0';
	    cub3d->map[cub3d->y_kord-2][cub3d->x_kord - 1] = 'N';
        cub3d->y_kord--;
    }
}

void turndown(t_cub3d *cub3d)
{
    player(cub3d);
    if (cub3d->map[cub3d->y_kord][cub3d->x_kord - 1] == '0')
    {
        my_mlx_pixel_put(cub3d, cub3d->x_kord - 1, cub3d->y_kord - 1, WHITE);
        my_mlx_pixel_put(cub3d, cub3d->x_kord - 1, cub3d->y_kord, RED);
	    cub3d->map[cub3d->y_kord-1][cub3d->x_kord - 1] = '0';
	    cub3d->map[cub3d->y_kord][cub3d->x_kord - 1] = 'N';
        cub3d->y_kord++;
    }
}