/* mouse example */
#include<iostream>
#include <graphics.h>
using namespace std;

void brush()
{
    int maxx, maxy;
    int x, y;
    maxx = getmaxx( );
    maxy = getmaxy( );


    setfillstyle(4, RED);
    setcolor(WHITE);
    settextstyle(DEFAULT_FONT, HORIZ_DIR, 2);
    outtextxy(20, 20, "Right click in to end.");

    bool red = true;
    while(!ismouseclick(WM_RBUTTONDBLCLK))
    {
        if(ismouseclick(WM_MOUSEMOVE))
        {
            getmouseclick(WM_MOUSEMOVE, x,  y);
            cout << "The mouse pointer is at: ";
            cout << "x=" << x;
            cout << "Y=" << y<<endl;
            setcolor(BLACK);
             if(ismouseclick(WM_LBUTTONDOWN))
            {
                cout<<"DWN"<<endl;
                setfillstyle(1,RED);
                setcolor(RED);
                red = (red) ? false : true;
                fillellipse(x,y,200,200);
            }
            if(ismouseclick(WM_LBUTTONUP))
            {
                 cout<<"UP"<<endl;
                clearmouseclick(WM_LBUTTONDOWN);
            }
            clearmouseclick(WM_LBUTTONUP);
            ellipse(x,y,0,360,50,50);
            //clearmouseclick(WM_LBUTTONUP);
        }

    }
}

int main(void)

{

    // Maximum x and y pixel coordinates

            // Coordinates of the mouse click


    // Put the machine into graphics mode and get the maximum coordinates:

    initwindow(1200, 720);

     brush();




    // Switch back to text mode:

    closegraph( );

}
