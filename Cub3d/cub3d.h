#ifndef CUB3D_H
# define CUB3D_H

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <math.h>
#include "minilibx/mlx.h"
#include "libft/libft.h"
#include "get_next_line/get_next_line.h"

#define PI 3.141592653

#define A 0
#define S 1
#define D 2
#define W 13
#define ESC 53

#define WINDOW_X 500
#define WINDOW_Y 500

#define SQR_X 50
#define SQR_Y 50
#define SQR_LENGTH 45

#define PLAYER 20

# define RED 0x00FF0000
# define GREEN 0x0000FF00
# define WHITE 0x00FFFFFF
# define BLACK 0x00000000

typedef struct s_player
{
    float x;
    float y;
    float dx;
    float dy;
    float angle;
}       t_player;

typedef struct cub3d
{
    void *mlx;
    void *mlx_win;
    t_player *player;
    char **map;
    char **map_input;
    int *addr;
    void *img;
    int y_kord;
    void *wall;
    void *floor;
    int line_length;
    int bits_per_pixel;
} t_cub3d;

int pushbutton(int keycode, t_cub3d *ptr);
void isargtrue(t_cub3d *cub3dptr);
int line_length(t_cub3d *cub3dptr);
void putimage(t_cub3d *cub3dptr);

#endif