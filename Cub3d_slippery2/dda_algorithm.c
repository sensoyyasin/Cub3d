#include "cub3d.h"

void ddaaaaaas(t_cub3d *img, float x1, float y1, float x2, float y2)
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
    int xinc;
    int yinc;

    double dx = x2 - x1;
    double dy = y2 - y1;
    if (fabs(dx) > fabs(dy))
        step = fabs(dx);
    else
        step = fabs(dy);
    if (step == 0)
        return; //baslangic ve bitis ayniysa.
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