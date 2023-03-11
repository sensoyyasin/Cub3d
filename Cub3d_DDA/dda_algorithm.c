#include "cub3d.h"

void dda(t_cub3d *img, double x1, double y1, double x2, double y2)
{
    //x1,y1 (2,2)
    //x2,y2 (9,2)
    //delta x = 9 - 2 = 7 //diff to x
    //delta y = 2 - 2 = 0 //diff to y
    // m = 0 / 7 = 0
    //steps = 7 which one is the big deltax or deltay
    //xinc = 7/7 = 1
    //yinc = 0 / 7 = 0;

    int step;
    
    double xinc;
    double yinc;

    double dx = x2 - x1;
    double dy = y2 - y1;
    if (fabs(dx) > fabs(dy))
        step = fabs(dx);
    else
        step = fabs(dy);
    if (step == 0)
        return;
    xinc = dx / step;
    yinc = dy / step;

    int i = 0;
    while (i <= step)
    {
        putpixel(img);
        x1 = x1 + xinc;
        y1 = y1 + yinc;
        i++;
    }
}