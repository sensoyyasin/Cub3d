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
		img->degree = 0;
	}
	else if (c == 'N')
	{
		img->angle = PI / 2;
		img->degree = 90;
	}
	else if (c == 'W')
	{
		img->angle = PI;
		img->degree = 180;
	}
	else if (c == 'S')
	{
		img->angle = (3 * PI / 2);
		img->degree = 270;
	}
}

void turnleft(t_cub3d *img)
{
    double newp_x = img->p_x - img->speed * sin(img->angle);
    double newp_y = img->p_y - img->speed * cos(img->angle);

    if(img->map[(int)newp_y][(int)newp_x] == '0' && img->check->a_check == true)
    {
		img->p_x = newp_x;
		img->p_y = newp_y;
    }
	else if (img->map[(int)newp_y][(int)img->p_x] == '0' && img->check->a_check == true)
		img->p_y = newp_y;
	else if (img->map[(int)img->p_y][(int)newp_x] == '0' && img->check->a_check == true)
		img->p_x = newp_x;
}

void turnright(t_cub3d *img)
{
    double newp_x = img->p_x + img->speed * sin(img->angle);
    double newp_y = img->p_y + img->speed * cos(img->angle);

    if(img->map[(int)newp_y][(int)newp_x] == '0' && img->check->d_check == true)
    {
		img->p_x = newp_x;
		img->p_y = newp_y;
    }
	else if (img->map[(int)newp_y][(int)img->p_x] == '0' && img->check->d_check == true)
		img->p_y = newp_y;
	else if (img->map[(int)img->p_y][(int)newp_x] == '0' && img->check->d_check == true)
		img->p_x = newp_x;
}

void turnup(t_cub3d *img)
{
    double newp_x = img->p_x + img->speed * cos(img->angle);
    double newp_y = img->p_y - img->speed * sin(img->angle);

    if (img->map[(int)newp_y][(int)newp_x] == '0' && img->check->w_check == true)
    {
		img->p_x = newp_x;
		img->p_y = newp_y;
    }
	else if (img->map[(int)newp_y][(int)img->p_x] == '0' && img->check->w_check == true)
		img->p_y = newp_y;
	else if (img->map[(int)img->p_y][(int)newp_x] == '0' && img->check->w_check == true)
		img->p_x = newp_x;
}

void turndown(t_cub3d *img)
{
    double newp_x = img->p_x - img->speed * cos(img->angle);
    double newp_y = img->p_y + img->speed * sin(img->angle);

    if (img->map[(int)newp_y][(int)newp_x] == '0'  && img->check->s_check == true)
    {
		img->p_x = newp_x;
		img->p_y = newp_y;
    }
	else if (img->map[(int)newp_y][(int)img->p_x] == '0' && img->check->s_check == true)
		img->p_y = newp_y;
	else if (img->map[(int)img->p_y][(int)newp_x] == '0' && img->check->s_check == true)
		img->p_x = newp_x;
}

void angleright(t_cub3d *img)
{
	if (img->check->r_check == true)
	{
		img->angle -= 0.1;
		if (img->angle < 0)
			img->angle += 2 * PI;
		img->angle_x = 1 * cos(img->angle);
		img->angle_y = 1 * sin(img->angle);
		// img->check->r_check = false;
	}
	printf("img angle : %f\n",img->angle);
	printf("x:%f, y:%f\n", img->angle_x, img->angle_y);
}

void angleleft(t_cub3d *img)
{
	if (img->check->l_check == true)
	{
		img->angle += 0.1;
		if (img->angle > 2 * PI)
			img->angle -= 2 * PI;
		img->angle_x = 1 * cos(img->angle);
		img->angle_y = 1 * sin(img->angle);
		// img->check->l_check = false;
	}
	printf("Img angle : %f\n",img->angle);
	printf("x:%f, y:%f\n", img->angle_x, img->angle_y);
}

// void drawRays3D(t_cub3d *img)
// {
// 	int mx,my,mp,dof;
// 	float rx,ry,ra,x0,y0;
// 	int i = 0;

// 	ra = img->angle;
// 	while (i < 1)
// 	{
// 		//Check horizontal lines
// 		dof = 0;
// 		float aTan = -1 / tan(ra);
// 		if (ra > PI) //looking up
// 		{
// 			ry = (((int)img->player->y >> 6) << 6) - 0.0001;
// 			rx = (img->player->y - ry) * aTan + img->player->x;
// 			y0 = -64;
// 			x0 = -y0 * aTan;
// 		}
// 		if (ra < PI) //looking up
// 		{
// 			ry = (((int)img->player->y >> 6) << 6) + 64;
// 			rx = (img->player->y - ry) * aTan + img->player->x;
// 			y0 = 64;
// 			x0 = -y0 * aTan;
// 		}
// 		if (ra == 0 || ra== PI) // looking straight left or right
// 		{
// 			rx = img->player->x;
// 			ry = img->player->y;
// 			dof = 8;
// 		}
// 		while (dof < 8)
// 		{
// 			mx = (int)(rx) >> 6;
// 			my = (int)(ry) >> 6;
// 			mp = (my * img->max_map_height) + mx;
// 			if (mp < img->max_map_height && img->map[mp] == 1)
// 				dof = 8;
// 			else
// 			{
// 				rx += x0;
// 				ry += y0;
// 				dof++;
// 			}
// 		}
// 	}
// 	i++;
// }