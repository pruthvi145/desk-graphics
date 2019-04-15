#include <graphics.h>
#include<iostream>
#include<math.h>

using namespace std;

void lineDDA(int x1, int y1, int x2, int y2);
void lineBresenhams(int x1, int y1, int x2, int y2);
void circleBresenhams(int x1, int y1, int x2, int y2);


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

void circleFill(int xc, int yc,int r)
{
   int x = 0;
   int y = r;
    int c=0;
   int d = 3 - 2*r;
   while(y>=x)
   {
       delay(100);
      //cleardevice();
      cout<<"(x, y) :"<<x<<", "<<y<<", "<<d<<endl ;
      //line(xc,yc,xc+x, yc+y);
      line(xc,yc,xc+x, yc-y);
      /*line(xc,yc,xc-x, yc+y);
      line(xc,yc,xc-x, yc-y);
      line(xc,yc,xc+y, yc+x);
      line(xc,yc,xc+y, yc-x);
      line(xc,yc,xc-y, yc+x);
      line(xc,yc,xc-y, yc-x);*/


      x+=2;
        if(d < 0)
        {
            d += 4*x+6;
        }
        else
        {
            y-=2;
            d += 4*(x-y)+10;
        }
        c++;
   }
   cout<<"C: "<<c;
}

void rotateLine(int xc, int yc, int x, int y,float angle, bool deg=true, bool fill=true)
{

    angle = (deg) ? angle * 3.1415/180 : angle; //To Radian
    float r = sqrt(pow(x-xc,2)+pow(y-yc,2));
    float X = r*cos(angle);
    float Y = r*sin(angle);
    cout<<"X: "<<X<<" Y: "<<Y<<endl;
    if(fill)
        line(xc,yc,xc+X,yc-Y);
    else
        putpixel(xc+X,yc-Y,15);
}
void fun()
{
    int m = 50,n=5, c=1;
    int count=0;
    for(int i=1;i<15;i++)
    {
        for(int j=1;j<15;j++)
        {
           for(int k=1;k<15;k++)
            {
                count++;
                if(n>=getmaxy())
                {
                    c++;
                    n=5;
                    m+=150;
                }
                if(m>=getmaxx() || m+100>=getmaxx())
                {
                    m=50;
                    n--;
                }
                    //cout<<"working"<<endl;
                    delay(1);

                    int c1 = (rand() % (255 - 0 + 1)) + 0;
                    int c2 = (rand() % (255 - 0 + 1)) + 0;
                    int c3 = (rand() % (255 - 0 + 1)) + 0;
                    cout<<"I: "<<c1<<" J: "<<c2<<" k: "<<c3<<endl;
                   setcolor(COLOR(c1,c2,c3));
                   setlinestyle(0,0,3);
                   line(m,n,m+100,n);
                   n+=5;

            }
        }
    }
    cout<<"COUNT: "<<count;

}
#define SIN(x) sin(x * 3.141592653589/180)
#define COS(x) cos(x * 3.141592653589/180)
void Ractangle(int left, int top, int right, int bottom)
{
    line(left,top,right,top);
    line(right,top,right,bottom);
    line(right,bottom,left,bottom);
    line(left,bottom,left,top);
}

void rotate(float a[][2], int n, int x_pivot,
					int y_pivot, int angle)
{
	int i = 0;
	while (i < n)
	{
		int x_shifted = a[i][0] - x_pivot;
		int y_shifted = a[i][1] - y_pivot;

		a[i][0] = abs(x_pivot + (x_shifted*COS(angle)
						- y_shifted*SIN(angle)));
		a[i][1] = y_pivot + (x_shifted*SIN(angle)
						+ y_shifted*COS(angle));
		i++;
	}
	for(int i=0; i<4; i++)
    {
        for(int j=0; j<2; j++)
        {
            cout<<a[i][j]<<"\t";
        }
        cout<<endl;
    }
	 Ractangle(a[0][0],a[0][1],a[2][0],a[2][1]);
}

int  main()
{
    int gd = DETECT, gm;
    initwindow(1000,1000,"My Window");


    fun();

    getch();
    closegraph();
    return 0;
}
