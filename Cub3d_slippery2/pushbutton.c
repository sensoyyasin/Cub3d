#include "cub3d.h"

void player(t_cub3d *cub3dptr)
{
    cub3dptr->x_kord = 0;
    cub3dptr->y_kord = 0;

    while (cub3dptr->map[cub3dptr->y_kord]) //değişti -> cub3dptr->map[cub3dptr->y_kord][cub3dptr->x_kord]
	{
		cub3dptr->x_kord = 0;
		while (cub3dptr->map[cub3dptr->y_kord][cub3dptr->x_kord] != '\0') //değişti -> cub3dptr->map[cub3dptr->y_kord][cub3dptr->x_kord] != '\n'
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

    if(img->map[(int)newp_y][(int)newp_x] == '0'  && img->map[(int)newp_y][(int)newp_x] == '0' && img->check->a_check == true)
    {
		img->p_x = newp_x;
		img->p_y = newp_y;
    }
}

void turnright(t_cub3d *img)
{
    double newp_x = img->p_x + img->speed;
    double newp_y = img->p_y;

    if(img->map[(int)newp_y][(int)newp_x] == '0' && img->map[(int)newp_y][(int)newp_x] == '0' && img->check->d_check == true)
    {
		img->p_x = newp_x;
		img->p_y = newp_y;
    }
}

void turnup(t_cub3d *img)
{
    double newp_x = img->p_x;
    double newp_y = img->p_y - img->speed;

    if (img->map[(int)newp_y][(int)newp_x] == '0' && img->map[(int)newp_y][(int)newp_x] == '0' && img->check->w_check == true)
    {
		img->p_x = newp_x;
		img->p_y = newp_y;
    }
}

void turndown(t_cub3d *img)
{
    double newp_x = img->p_x;
    double newp_y = img->p_y + img->speed;

    if (img->map[(int)newp_y][(int)newp_x] == '0' && img->map[(int)newp_y][(int)newp_x] == '0' && img->check->s_check == true)
    {
		img->p_x = newp_x;
		img->p_y = newp_y;
    }
}