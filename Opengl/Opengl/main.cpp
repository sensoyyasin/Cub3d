//
//  main.cpp
//  Opengl
//
//  Created by yasin şensoy on 2.03.2023.
//

#include "math.h"
#include "stdio.h"
#include "stdlib.h"
#include <OpenGL/gl.h>
#include <OpenGl/glu.h>
#include <GLUT/glut.h>
#define PI 3.1415926535
#define P2 PI/2
#define P3 3*PI/2
#define P4 0
#define DR 0.0174533 //one degree in radians

float px,py,pdx,pdy,pa; //player position

int mapX = 8;
int mapY = 8;
int mapS = 64;

int map[] =
{
    1,1,1,1,1,1,1,1,
    1,0,0,0,0,0,0,1,
    1,0,1,0,0,1,0,1,
    1,0,0,0,0,0,0,1,
    1,0,0,0,0,1,0,1,
    1,0,0,0,0,0,0,1,
    1,0,0,0,0,0,0,1,
    1,1,1,1,1,1,1,1,
};

void drawMap2D()
{
 int x,y,xo,yo;
 for(y=0;y<mapY;y++)
 {
  for(x=0;x<mapX;x++)
  {
   if(map[y*mapX+x]==1){ glColor3f(1,1,1);} else{ glColor3f(0,0,0);}
   xo=x*mapS; yo=y*mapS;
   glBegin(GL_QUADS);
   glVertex2i(xo+1,yo+1);
   glVertex2i(xo+1,mapS+yo-1);
   glVertex2i(mapS+xo-1, mapS+yo-1);
   glVertex2i(mapS+xo-1,yo+1);
   glEnd();
  }
 }
}

void drawPlayer()
{
    glColor3f(1, 1, 0);
    glPointSize(8);
    glBegin(GL_POINTS); //karenin kose koordinatlarina nokta koyar.
    glVertex2i(px, py);
    glEnd();
    
    glLineWidth(3);
    glBegin(GL_LINES);
    glVertex2i(px,py);
    glVertex2i(px+pdx*5, py+pdy*5);
    glEnd();
}

float dist(float ax, float ay, float bx, float by, float ang)
{
    return (sqrt(bx - ax)* (bx - ax) + (by - ay) * (by - ay));
}

void drawRays3D()
{
    int r,mx,my,mp,dof;
    float rx,ry,ra,x0,y0,disT;
    ra = pa - DR * 30;
    if (ra < 0)
    {
        ra += 2* PI;
        if (ra > 2*PI)
        {
            ra -= 2*PI;
        }
    }
    for (r = 0; r < 30; r++)
    {
        //--check horizontal lines--
        dof = 0;
        float disH = 1000000,hx=px,hy=py;
        float aTan=-1/tan(ra);
        if (ra > PI)
        {
            ry = (((int)py>>6)<<6) - 0.0001;
            rx = (py-ry)*aTan + px;
            y0 = -64;
            x0 = -y0*aTan;
        }
        if (ra < PI)
        {
            ry = (((int)py>>6)<<6) + 64;
            rx = (py-ry)*aTan + px;
            y0 = 64;
            x0 = -y0*aTan;
        }
        //looking straight left or right
        if (ra == 0 || ra == PI)
        {
            rx = px;
            ry = py;
            dof = 8;
        }
        while (dof < 8)
        {
            mx = (int)(rx) >> 6; my = (int)(ry) >> 6;
            mp = my * mapX + mx;
            //hit wall
            if (mp > 0 && mp < mapX * mapY && map[mp] == 1)
            {
                hx = rx;
                hy = ry;
                disH = dist(px,py,hx,hy,ra);
                dof = 8;
            }
            //next line
            else
            {
                rx += x0;
                ry += y0;
                dof++;
            }
        }
    //--check vertical lines--
    dof = 0;
    float disV = 1000000,vx=px,vy=py, disT = disV;
    float nTan = -tan(ra);
    if (ra > P2 && ra < P3)
    {
        rx = (((int)px>>6)<<6) - 0.0001;
        ry = (px-rx)*nTan + py;
        x0 = -64;
        y0 = -x0*nTan;
    }
    if (ra < P2 || ra > P3)
    {
        rx = (((int)px>>6)<<6) + 64;
        ry = (px-rx)*nTan + py;
        x0 = 64;
        y0 = -x0*nTan;
    }
    //looking straight left or right
    if (ra == 0 || ra == PI)
    {
        rx = px;
        ry = py;
        dof = 8;
    }
    while (dof < 8)
    {
        mx = (int)(rx) >> 6; my = (int)(ry) >> 6;
        mp = my * mapX + mx;
        //hit wall
        if (mp > 0 && mp < mapX * mapY && map[mp] == 1)
        {
            vx=rx;
            vy=ry;
            disV = dist(px,py,vx,vy,ra);
            dof = 8;
        }
        //next line
        else
        {
            rx += x0;
            ry += y0;
            dof++;
        }
        if (disV < disH)
        {
            rx = vx;
            ry = vy;
            disT = disV;
        }
        if (disH < disV)
        {
            rx = hx;
            ry = hy;
            disT = disH;
        }
        glColor3f(1, 0, 0);
        glLineWidth(3);
        glBegin(GL_LINES);
        glVertex2i(px, py);
        glVertex2i(rx, ry);
        glEnd();
        ra += DR;
        // Draw 3D Walls
        float ca = pa - ra;
        if (ca < 0)
        {
            ca += 2* PI;
            if (ca > 2*PI)
            {
                ca -= 2*PI;
            }
        }
        disT = disT * cos(ca); // fix fisheye
        float lineH = (mapS*320 / disT);
        if (lineH > 320)
        {
            lineH = 320;
        }
        float lineo = 160 - lineH / 2;
        glLineWidth(8);
        glBegin(GL_LINES);
        glVertex2i(r*8+530, lineo);
        glVertex2i(r*8+530,lineH + lineo);
        glEnd();
        if (ra < 0)
        {
            ra += 2* PI;
            if (ra > 2*PI)
            {
                ra -= 2*PI;
            }
        }
    }
}
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    drawMap2D();
    drawPlayer();
    drawRays3D();
    glutSwapBuffers();
}

void buttons(unsigned char key, int x, int y)
{
    //printf("key : %d",key);
    if (key == 'a')
    {
        pa -= 0.1;
        if (pa < 0)
            pa += 2*PI;
        pdx = cos(pa) * 5;
        pdy = sin(pa) * 5;
    }
    if (key == 'd')
    {
        pa += 0.1;
        if (pa > 2*PI)
            pa -= 2*PI;
        pdx = cos(pa) * 5;
        pdy = sin(pa) * 5;
    }
    if (key == 'w')
    {
        px += pdx;
        py += pdy;
    }
    if (key == 's')
    {
        px -= pdx;
        py -= pdy;
    }
    if (key == 27)
    {
        printf("The game is closing\n");
        exit(1);
    }
    glutPostRedisplay();
}

void init()
{
    glClearColor(0.3,0.3,0.3,0); //Arka plan rengi
    gluOrtho2D(0, 1024, 512, 0); //GLUT pencere ekran cizim alani buyuklugu
    px = 300;
    py = 300;
    pdx = cos(pa) * 5;
    pdy = sin(pa) * 5;
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowSize(1024, 512);
    glutCreateWindow("Cub3d");
    init();
    glutDisplayFunc(display);
    glutKeyboardFunc(buttons);
    glutMainLoop();
}
