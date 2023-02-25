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
	int no;
	int so;
	int we;
	int ea;
	int f;
	int c;
	int texture_bool;
	int map_bool;
	char *no_path; //will be freed from here
	char *so_path;
	char *we_path;
	char *ea_path; //will be freed to here
	int f_color[3];
	int c_color[3];
} t_cub3d;

int pushbutton(int keycode, t_cub3d *ptr);
void isargtrue(t_cub3d *cub3dptr);
int line_length(t_cub3d *cub3dptr);
void putimage(t_cub3d *cub3dptr);
void mapcheck(t_cub3d *cub3dptr);
void check_all(t_cub3d *img);
void free_all(t_cub3d *img);
void exit_func(char *err, t_cub3d *img);
void split_comp(char **split, t_cub3d *img);
void mapcheck2(char *words, t_cub3d *img);
void exit_split_func(char **split, t_cub3d *img);
void free_split(char **split);
void exit_double_split_func(char **split, char **color, t_cub3d *img);
char *clear_endstr(char *str);
int is_number(char *str);
void mapdrawcheck(char *words, t_cub3d *img);

#endif