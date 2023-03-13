#include "cub3d.h"

int pushbutton(int keycode, t_cub3d *ptr)
{
	(void)keycode;
	mlx_destroy_window(ptr->mlx, ptr->mlx_win);
	exit_func("\033[35m\nGame was closing\n", ptr);
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
	if (img->check->l_check == true)
		angleleft(img);
	if (img->check->r_check == true)
		angleright(img);
}

int keychecker(int keycode, t_cub3d *ptr)
{
	printf("%d\n", keycode);
	if (keycode == ESC || keycode == 65307)
		pushbutton(keycode, ptr);
	if (keycode == W || keycode == 'w')
		ptr->check->w_check = true;
	if (keycode == A || keycode == 'a')
		ptr->check->a_check = true;
	if (keycode == S || keycode == 's')
		ptr->check->s_check = true;
	if (keycode == D || keycode == 'd')
		ptr->check->d_check = true;
	if (keycode == L || keycode == 65361)
		ptr->check->l_check = true;
	if (keycode == R || keycode == 65363)
		ptr->check->r_check = true;
	return (1);
}

int keychecker2(int keycode, t_cub3d *ptr)
{
	if (keycode == W || keycode == 'w')
		ptr->check->w_check = false;
	if (keycode == A || keycode == 'a')
		ptr->check->a_check = false;
	if (keycode == S || keycode == 's')
		ptr->check->s_check = false;
	if (keycode == D || keycode == 'd')
		ptr->check->d_check = false;
	if (keycode == L || keycode == 65361)
		ptr->check->l_check = false;
	if (keycode == R || keycode == 65363)
		ptr->check->r_check = false;
	return (1);
}