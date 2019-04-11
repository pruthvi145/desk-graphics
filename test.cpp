#include <graphics.h>
#include<iostream>
#include<math.h>

using namespace std;

void lineDDA(int x1, int y1, int x2, int y2);
void lineBresenhams(int x1, int y1, int x2, int y2);


void lineDDA(int x1, int y1, int x2, int y2)
{
    int dx = x2 - x1;
    int dy = y2 - y1;

    int steps = (abs(dx) >= abs(dy)) ? abs(dx) : abs(dy);

    float Xinc = dx / (float)steps;
    float Yinc = dy / (float)steps;

    float x = x1;
    float y = y1;

    for(int i=0; i<=steps; i++)
    {
        //cout<<"(x, y) :"<<round(x)<<", "<<round(y)<<endl ;
        putpixel(round(x),round(y), WHITE);
        x += Xinc;
        y += Yinc;
    }
}

void lineBresenhams(int x1, int y1, int x2, int y2)
{
    /**
        dx > dy AND x1<x2, y1<y2    => 0 < m < 1
                                    => dx,dy > 0
    **/

    int dx = x2 - x1;
    int dy = y2 - y1;
    int sdx = (x2>=x1) ? 1 : -1;
    int sdy = (y2>=y1) ? 1 : -1;
    bool ex = false;

    if(dy > dx)
    {
        ex = true;
        int temp;
        temp = dx;
        dx = dy;
        dy = temp;
    }

    int d = 2*dy - dx;
    int de = 2*dy;
    int dne = 2*(dy-dx);
    int y = y1;
    int x = x1;
    int steps = 0;
    while(steps<=dx)
    {
        //cout<<"(x, y) :"<<x<<", "<<y<<", "<<d<<endl ;
        putpixel(x,y,WHITE);

        if(d<0) //East
        {
            d += de;
            if(ex) y += sdy;
            else x += sdx;
        }
        else  // North_Earth
        {
            y += sdy;
            x += sdx;
            d += dne;
        }
        steps++;
    }
}
void circleBresenhams(int xc, int yc, int r)
{
    int x = 0;
    int y = r;

    int d = 3 - 2*r;
    while(y>=x)
    {

        putpixel(xc+x, yc+y, WHITE);
        putpixel(xc+x, yc-y, WHITE);
        putpixel(xc-x, yc+y, WHITE);
        putpixel(xc-x, yc-y, WHITE);
        putpixel(xc+y, yc+x, WHITE);
        putpixel(xc+y, yc-x, WHITE);
        putpixel(xc-y, yc+x, WHITE);
        putpixel(xc-y, yc-x, WHITE);

        x++;
        if(d < 0)
        {
            d += 4*x+6;
        }
        else
        {
            y--;
            d += 4*(x-y)+10;
        }
    }
}
main()
{
   int gd = DETECT, gm;
   initgraph(&gd,&gm,"");
   circleBresenhams(100,100,50);


   getch();
   closegraph();
   return 0;
}
