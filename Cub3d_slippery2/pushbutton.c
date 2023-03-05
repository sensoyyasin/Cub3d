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
				convertangle(cub3dptr->map[cub3dptr->y_kord][cub3dptr->x_kord], cub3dptr);
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

void convertangle(char c, t_cub3d *img)
{
	if (c == 'E')
	{
		img->angle = 0;
		img->angle_x = 1;
		img->angle_y = 0;
		img->degree = 0;
	}
	else if (c == 'N')
	{
		img->angle = PI / 2;
		img->angle_x = 0;
		img->angle_y = 1;
		img->degree = 90;
	}
	else if (c == 'W')
	{
		img->angle = PI;
		img->angle_x = -1;
		img->angle_y = 0;
		img->degree = 180;
	}
	else if (c == 'S')
	{
		img->angle = (3 * PI / 2);
		img->angle_x = 0;
		img->angle_y = -1;
		img->degree = 270;
	}
}

void turnleft(t_cub3d *img)
{
    double newp_x = img->p_x - img->speed;
    double newp_y = img->p_y;

    if(img->map[(int)newp_y][(int)newp_x] == '0' && img->check->a_check == true)
    {
		img->p_x = newp_x;
		img->p_y = newp_y;
    }
}

void turnright(t_cub3d *img)
{
    double newp_x = img->p_x + img->speed;
    double newp_y = img->p_y;

    if(img->map[(int)newp_y][(int)newp_x] == '0' && img->check->d_check == true)
    {
		img->p_x = newp_x;
		img->p_y = newp_y;
    }
}

void turnup(t_cub3d *img)
{
    double newp_x = img->p_x;
    double newp_y = img->p_y - img->speed;

    if (img->map[(int)newp_y][(int)newp_x] == '0' && img->check->w_check == true)
    {
		img->p_x = newp_x;
		img->p_y = newp_y;
    }
}

void turndown(t_cub3d *img)
{
    double newp_x = img->p_x;
    double newp_y = img->p_y + img->speed;

    if (img->map[(int)newp_y][(int)newp_x] == '0'  && img->check->s_check == true)
    {
		img->p_x = newp_x;
		img->p_y = newp_y;
    }
}

void angleright(t_cub3d *img)
{
	if (img->angle_x == 0 && img->angle_y == 1 && img->check->r_check == true)
	{
		img->angle_x = 1;
		img->angle_y = 0;
		img->degree = 0;
		img->check->r_check = false;
	}
	else if (img->angle_x == 1 && img->angle_y == 0 && img->check->r_check == true)
	{
		img->angle_x = 0;
		img->angle_y = -1;
		img->degree = 270;
		img->check->r_check = false;
	}
	else if (img->angle_x == 0 && img->angle_y == -1 && img->check->r_check == true)
	{
		img->angle_x = -1;
		img->angle_y = 0;
		img->degree = 180;
		img->check->r_check = false;
	}
	else if (img->angle_x == -1 && img->angle_y == 0 && img->check->r_check == true)
	{
		img->angle_x = 0;
		img->angle_y = 1;
		img->degree = 90;
		img->check->r_check = false;
	}
	printf("x:%f, y:%f\n", img->angle_x, img->angle_y);
}

void angleleft(t_cub3d *img)
{
	if (img->angle_x == 0 && img->angle_y == 1 && img->check->l_check == true)
	{
		img->angle_x = -1;
		img->angle_y = 0;
		img->degree = 180;
		img->check->l_check = false;
	}
	else if (img->angle_x == -1 && img->angle_y == 0 && img->check->l_check == true)
	{
		img->angle_x = 0;
		img->angle_y = -1;
		img->degree = 270;
		img->check->l_check = false;
	}
	else if (img->angle_x == 0 && img->angle_y == -1 && img->check->l_check == true)
	{
		img->angle_x = 1;
		img->angle_y = 0;
		img->degree = 0;
		img->check->l_check = false;
	}
	else if (img->angle_x == 1 && img->angle_y == 0 && img->check->l_check == true)
	{
		img->angle_x = 0;
		img->angle_y = 1;
		img->degree = 90;
		img->check->l_check = false;
	}
}