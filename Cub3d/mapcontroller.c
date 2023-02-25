#include "cub3d.h"

void isargtrue(t_cub3d *cub3dptr)
{
    int len;

    len = ft_strlen2(cub3dptr->map_input[1]);
    if (cub3dptr->map_input[1][len - 1] != 'b' &&
        cub3dptr->map_input[1][len - 2] != 'u' &&
        cub3dptr->map_input[1][len - 3] != 'c' &&
        cub3dptr->map_input[1][len - 4] != '.')
        {
			printf("\033[1;31mWrong map format!\n\033[0m"); //change
           	//write(2, "Error\n", 6);
		    exit(1);
        }
}

void mapcheck(t_cub3d *cub3dptr)
{
    int fd_map;
    int uz_y;
    
    uz_y = -1;
    fd_map = open(cub3dptr->map_input[1], O_RDONLY);
    if (fd_map < 0)
	{
		printf("\033[1;31mFile could not be opened!\n\033[0m");
		exit(0);
	}
    cub3dptr->y_kord = 0;
    cub3dptr->map = malloc((sizeof(char *)) * 1024);
    while (++uz_y < line_length(cub3dptr))
    {
		//printf("\033[1;31mline length: %d\n\033[0m", line_length(cub3dptr)); //sil
		cub3dptr->map[uz_y] = get_next_line(fd_map);
        //mapcheck2(cub3dptr->map[uz_y]);
		printf("%s",cub3dptr->map[uz_y]);
    }
    close(fd_map);
}