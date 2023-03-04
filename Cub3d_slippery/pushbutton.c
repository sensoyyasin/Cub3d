#include "cub3d.h"

int pushbutton(int keycode, t_cub3d *ptr)
{
    //en sonda cukur problemi
    if (keycode == ESC)
    {
        mlx_destroy_window(ptr->mlx, ptr->mlx_win);
        exit_func("\033[35m\nGame was closing\n", ptr);
    }
    if (keycode == W)
        turnup(ptr);
    if (keycode == A)
        turnleft(ptr);
    if (keycode == S)
        turndown(ptr);
    if (keycode == D)
        turnright(ptr);
    return (0);
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
                cub3dptr->p_x = (double)(cub3dptr->x_kord);
                cub3dptr->p_y = (double)(cub3dptr->y_kord);
                cub3dptr->map[cub3dptr->y_kord][cub3dptr->x_kord] = '0';
			    return ;
            }
            cub3dptr->x_kord++;
		}
		cub3dptr->y_kord++;
	}
}

void turnleft(t_cub3d *img)
{
    double newp_x = img->p_x - img->speed;
    double newp_y = img->p_y;

    if(img->map[(int)newp_y][(int)newp_x] == '0'  && img->map[(int)newp_y][(int)newp_x] == '0')
    {
		img->p_x = newp_x;
		img->p_y = newp_y;
		//putimage(img);
    }
}

void turnright(t_cub3d *img)
{
    double newp_x = img->p_x + img->speed;
    double newp_y = img->p_y;

    if(img->map[(int)newp_y][(int)newp_x] == '0' && img->map[(int)newp_y][(int)newp_x] == '0')
    {
		img->p_x = newp_x;
		img->p_y = newp_y;
		//putimage(img);
    }
}

void turnup(t_cub3d *img)
{
    double newp_x = img->p_x;
    double newp_y = img->p_y - img->speed;

    if(img->map[(int)newp_y][(int)newp_x] == '0' && img->map[(int)newp_y][(int)newp_x] == '0')
    {
		img->p_x = newp_x;
		img->p_y = newp_y;
		//putimage(img);
    }
}

void turndown(t_cub3d *img)
{
    double newp_x = img->p_x;
    double newp_y = img->p_y + img->speed;

    if(img->map[(int)newp_y][(int)newp_x] == '0' && img->map[(int)newp_y][(int)newp_x] == '0')
    {
		img->p_x = newp_x;
		img->p_y = newp_y;
		//putimage(img);
    }
}