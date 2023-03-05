#include "cub3d.h"

int pushbutton(int keycode, t_cub3d *ptr)
{
    if (keycode == ESC)
    {
        mlx_destroy_window(ptr->mlx, ptr->mlx_win);
        exit_func("\033[35m\nGame was closing\n", ptr);
    }
    return (0);
}

void keycheckforloop(t_cub3d *img)
{
    if (img->check->w_check == true)
        turnup(img);
 	if (img->check->a_check == true)
        turnleft(img);
    if (img->check->s_check == true)
        turndown(img);
    if (img->check->d_check == true)
        turnright(img);
}

int keychecker(int keycode, t_cub3d *ptr)
{
	if (keycode == ESC)
		pushbutton(keycode, ptr);
	if (keycode == W)
		ptr->check->w_check = true;
	if (keycode == A)
		ptr->check->a_check = true;
	if (keycode == S)
		ptr->check->s_check = true;
	if (keycode == D)
		ptr->check->d_check = true;
	return (1);
}

int keychecker2(int keycode, t_cub3d *ptr)
{
	if (keycode == W)
		ptr->check->w_check = false;
	if (keycode == A)
		ptr->check->a_check = false;
	if (keycode == S)
		ptr->check->s_check = false;
	if (keycode == D)
		ptr->check->d_check = false;
	return (1);
}