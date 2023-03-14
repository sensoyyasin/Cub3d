#ifndef CUB3D_H
# define CUB3D_H

#include <stdbool.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <math.h>
#include "minilibx/mlx.h"
#include "libft/libft.h"
#include "get_next_line/get_next_line.h"

#define PI 3.141592653
#define DR 0.0174533

#define WINDOW_WIDTH 1080
#define WINDOW_HEIGHT 720
#define ANGLE_CAMERA 60
#define TAB 48

#define A 0
#define S 1
#define D 2
#define W 13
#define ESC 53
#define L 123 //75
#define R 124 //77

# define RED 0x00FF0000
# define GREEN 0x0000FF00
# define WHITE 0x00FFFFFF
# define BLACK 0x00000000
# define MAGENTA 0x00FF00FF
# define CYAN 0x8000FFFF

typedef struct s_bool
{
    bool w_check;
    bool a_check;
    bool s_check;
    bool d_check;
    bool r_check;
    bool l_check;
    bool tab_check;
}   t_check;

typedef struct cub3d
{
    void *mlx;
    void *mlx_win;
    t_check *check;
    char **map;
    char **map_input;
    int *addr;
    void *img;
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
	int max_map_width;
	int max_map_height;
	char *no_path; //will be freed from here
	char *so_path;
	char *we_path;
	char *ea_path; //will be freed to here
	int f_color[3];
	int c_color[3];
    int n_timer;
    int s_timer;
    int e_timer;
    int w_timer;
    int x_kord;
    int y_kord;
    double p_x;
    double p_y;
    int speed_pixel;
    int pixel;
    double speed;
    double angle;
    double degree;
    float angle_x;
    float angle_y;
} t_cub3d;

int pushbutton(int keycode, t_cub3d *ptr);
void isargtrue(t_cub3d *cub3dptr);
int line_length(t_cub3d *cub3dptr);
void putpixel(t_cub3d *cub3dptr);
void mapcheck(t_cub3d *cub3dptr);
void check_all(t_cub3d *img);
void free_all(t_cub3d *img);
void exit_func(char *err, t_cub3d *img);
void split_comp(char **split, t_cub3d *img);
void mapcheck2(char *words, t_cub3d *img);
void mapcheck3(char *words, t_cub3d *img);
void exit_split_func(char **split, t_cub3d *img);
void free_split(char **split);
void exit_double_split_func(char **split, char **color, t_cub3d *img);
char *clear_endstr(char *str);
int is_number(char *str);
void mapdrawcheck(char *words, t_cub3d *img);
void ismaptrue(char *words, t_cub3d *img);
void double_free_split(char **split1, char **split2);
void realmapcheck(int i, t_cub3d *img);
void my_mlx_pixel_put(t_cub3d *img, int x, int y, int color);
void my_mlx_pixel_put2(t_cub3d *img);
void player(t_cub3d *cub3dptr);
void turnleft(t_cub3d *cub3d);
void turnup(t_cub3d *cub3d);
void turnright(t_cub3d *cub3d);
void	turndown(t_cub3d *cub3d);
int		putimage(t_cub3d *img);
void	map_addr(t_cub3d *img);
int		keychecker(int keycode, t_cub3d *ptr);
int		keychecker2(int keycode, t_cub3d *ptr);
void	keycheckforloop(t_cub3d *img);
void    convertangle(char c, t_cub3d *img);
void angleright(t_cub3d *img);
void angleleft(t_cub3d *img);
double distance(double ax, double ay, double bx, double by);
void dda(t_cub3d *img, double x1, double y1, double x2, double y2);
void    my_mlx_pixe_put_angle(t_cub3d *img);
void draw3DWalls(t_cub3d *img, int i, int j, double distance_to_wall);
void my_mlx3_pixel_put_image(t_cub3d *img, int x, int y, int color);

#endif