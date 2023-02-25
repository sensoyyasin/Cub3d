#include "cub3d.h"

int pushbutton(int keycode, t_cub3d *ptr)
{
    if (keycode == ESC)
    {
        //write(2, "\033[35mGame was closing\n", 22);
        mlx_destroy_window(ptr->mlx, ptr->mlx_win);
        exit_func("\033[35mGame was closing\n", ptr);
    }
    else if (keycode == W || keycode == A || keycode == S || keycode == D)
        return (1);
    return (0);
}