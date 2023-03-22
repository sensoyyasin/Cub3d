#include "cub3d.h"

// void	raycasting(t_cub3d *img, double angle, int ray_counter)
// {
// 	double distance_v;
// 	double distance_h;
// 	double distance;
// 	int dir_x = ((cos(angle * (PI / 180)) > 0) * 2) - 1;
// 	int dir_y = ((sin(angle * (PI / 180)) > 0) * -2) + 1;
// 	bool hitv = false;
// 	bool hith = false;
// 	distance_v = ray_vertical(img, angle, dir_x, dir_y, &hitv); //dikey
// 	distance_h = ray_horizonal(img, angle, dir_x, dir_y, &hith); //yatay

// 	if (distance_v < distance_h)
// 	{
// 		distance = distance_v;
// 		img->_hith = false;
// 		img->_hitv = true;
// 	}
// 	else
// 	{
// 		distance = distance_h;
// 		img->_hith = true;
// 		img->_hitv = false;
// 	}
// 	double original_dist = distance;
// 	distance = distance * fabs(cos((img->degree - img->angle) * (PI / 180)));
// 	draw_ray(distance, dir_x, dir_y, img, angle, ray_counter, original_dist);
// }

// double	ray_vertical(t_cub3d *img, double angle, double dir_x, double dir_y, bool *hit)
// {
// 	double vdy;
// 	double vdx;

// 	if (dir_x == -1)
// 		vdx = img->p_x - floor(img->p_x);
// 	else
// 		vdx = ceil(img->p_x) - img->p_x;
// 	vdy = fabs(tan(angle * (PI / 180)) * vdx);

// 	double tmp_x = vdx*dir_x;
// 	double tmp_y = vdy*dir_y;
// 	while (img->p_x + vdx*dir_x - 0.0001 >= 0 && img->p_x + vdx*dir_x - 0.0001 <= img->max_x
// 	&& img->p_y + vdy * dir_y >= 0)
// 	{
// 		vdx = vdx + 0.0001;
// 		if (is_wall_v2(img->p_x + vdx * dir_x, img->p_y + vdy * dir_y, img))
// 		{
// 			*hit = true;
// 			tmp_x = vdx * dir_x;
// 			tmp_y = vdy * dir_y;
// 			break;
// 		}
// 		vdx = vdx + 1 - 0.0001;
// 		vdy = fabs(tan(angle * (PI / 180)) * vdx);
// 	}
// 	double distance;
// 	if (*hit == true)
// 		distance = sqrt((tmp_x*tmp_x) + (tmp_y*tmp_y));
// 	else
// 		distance = 10000;
// 	return (distance);
// }

// double ray_horizonal(t_cub3d *img, double angle, double dir_x, double dir_y, bool *hit)
// {
// 	double hdy;
// 	double hdx;

// 	if (dir_y == -1)
// 		hdy = img->p_y - floor(img->p_y);
// 	else
// 		hdy = ceil(img->p_y) - img->p_y;
// 	hdx = fabs(hdy / tan(angle * (PI / 180)));

// 	double tmp_y = hdy * dir_y;
// 	double tmp_x = hdx * dir_x;
// 	while (img->p_x + hdx * dir_x >= 0 && img->p_x + hdx * dir_x <= img->max_x
// 	&& img->p_y + hdy*dir_y - 0.0001 >= 0 && img->p_y + hdy * dir_y - 0.0001 <= img->max_y)
// 	{
// 		hdy = hdy + 0.0001;
// 		if (is_wall_v2(img->p_x + hdx * dir_x, img->p_y + hdy * dir_y, img))
// 		{
// 			*hit = true;
// 			tmp_x = hdx*dir_x;
// 			tmp_y = hdy*dir_y;
// 			break;
// 		}
// 		hdy = hdy + 1 - 0.0001;
// 		hdx = fabs(hdy / tan(angle * (PI / 180)));
// 	}

// 	double distance;
// 	if (*hit == true)
// 		distance = sqrt((tmp_x*tmp_x) + (tmp_y*tmp_y));
// 	else
// 		distance = 10000;
// 	return (distance);
// }

// int is_wall_v2(double x, double y, t_cub3d *img)
// {
// 	int xX;
// 	int yY;

// 	xX = (int)floor(x);
// 	yY = (int)floor(y);
// 	return (ft_strchr("0NSEW", img->map[yY][xX]) == NULL);
// }

// void draw_ray(double distance, int dir_x, int dir_y, t_cub3d *img, double angle, int ray_count, double original_dist)
// {
//     double    ray_x;
//     double    ray_y;
//     double    dx;
//     double    dy;

// 	ray_x = img->p_x;
// 	ray_y = img->p_y;
//     dx = distance * fabs(cos(angle * (PI / 180))) * dir_x;
//     dy = distance * fabs(sin(angle * (PI / 180))) * dir_y;
//     while (1)
//     {
//         if (!is_wall(ray_x, ray_y, img) && (sqrt(((img->p_x - ray_x) * (img->p_x - ray_x)) + ((img->p_y - ray_y) * (img->p_y - ray_y))) <= original_dist))
//             img->addr_map[(img->pixel * (img->max_x + 1)) * (int)floor(img->pixel * ray_y) + (int)floor(img->pixel * ray_x)] = 0x00ff00;
//         else
// 		{
// 			_3D(img, distance, ray_count);
//             break;
// 		}
//         ray_x += dx / (WINDOW_HEIGHT / 2);
//         ray_y += dy / (WINDOW_HEIGHT / 2);
//     }
// }

// int is_wall(double x, double y, t_cub3d *img)
// {
// 	int xX;
// 	int yY;

// 	if (x < 0 || x > img->max_x || y < 0 || y > img->max_y)
// 		return (1);
//     xX = floor(x);
//     yY = floor(y);
// 	if (img->map[yY][xX] != '1')
// 		return (0);
//     return (1);
// }

// void _3D(t_cub3d *img, double distance, int ray_count)
// {
// 	int loc;
// 	int mid;
// 	double oran;
// 	int	i;
// 	int color;
// 	distance = distance * (double)img->pixel * ((double)WINDOW_HEIGHT / (double)WINDOW_WIDTH);
// 	i = 0;
// 	mid = WINDOW_HEIGHT / 2.0;
// 	loc = (WINDOW_HEIGHT * mid) - ray_count;
// 	oran = (((double)WINDOW_HEIGHT / 2.0) / distance) * (double)img->pixel;

// 	if (img->_hith == true)
// 		color = 0x400000;
// 	else if (img->_hitv == true)
// 		color = 0x000040;
// 	else
// 		color = 0x00ff00; //error
// }