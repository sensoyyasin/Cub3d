/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushbutton.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtemel <mtemel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 21:48:07 by yasinsensoy       #+#    #+#             */
/*   Updated: 2023/03/23 13:07:26 by mtemel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	player(t_cub3d *cub3dptr)
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

void	convertangle(char c, t_cub3d *img)
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

void	turnleft(t_cub3d *img)
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

	//img->check->a_check = false;
}

void	turnright(t_cub3d *img)
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

	//img->check->d_check = false; -> Hatali.
}

void	turnup(t_cub3d *img)
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
	//img->check->w_check = false;
}

void	turndown(t_cub3d *img)
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

	//img->check->s_check = false;
}

void	angleright(t_cub3d *img)
{
	img->angle -= 0.1;
	if (img->angle > (2 * PI))
		img->angle -= 2 * PI;
	img->angle_x = cos(img->angle);
	img->angle_y = sin(img->angle);
}

void	angleleft(t_cub3d *img)
{
	img->angle += 0.1;
	if (img->angle <= 0)
		img->angle += 2 * PI;
	img->angle_x = cos(img->angle);
	img->angle_y = sin(img->angle);

	//img->check->l_check = false;
	//printf("Img angle : %f\n",img->angle);
	//printf("x:%f, y:%f\n", img->angle_x, img->angle_y);
}
