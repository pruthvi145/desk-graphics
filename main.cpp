#include <graphics.h>
#include<iostream>
#include "CustomGraphics.h"

using namespace std;

void animatedLine(int X0, int Y0, int X1, int Y1,int delayTime=0, int color=0)
{

    int dx = X1 - X0;
    int dy = Y1 - Y0;


    int steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy);

    float Xinc = dx / (float) steps;
    float Yinc = dy / (float) steps;


    float X = X0;
    float Y = Y0;
    for (int i = 0; i <= steps; i++)
    {
        putpixel (X,Y,color);
        X += Xinc;
        Y += Yinc;
        delay(delayTime);

    }
}

void animatedRectangle(int left, int top, int right, int bottom, int delayTime=0, int color=0)
{
    animatedLine(left,top,right,top,delayTime,color);
    animatedLine(right,top,right,bottom,delayTime,color);
    animatedLine(right,bottom,left,bottom,delayTime,color);
    animatedLine(left,bottom,left,top,delayTime,color);
}
void background()
{
    setfillstyle(1,12);
    floodfill(0,0,15);
}

void desk(int x=72, int y=517)
{
    /* Surface Parameter */
    const int deskWidth=880;
    const int deskHeight=50;

    /* Legs Parameter */
    const int legWidth=45;
    const int legHeight=200;
    const int legX=x+70;
    const int legY=y+deskHeight;
    const int legX2=legX+legWidth+650;
    const int legY2=legY;

    /** Legs **/
    setfillstyle(1,15);
    bar(legX,legY,legX+legWidth,legY+legHeight);
    bar(legX2,legY2,legX2+legWidth,legY2+legHeight);

    /** Surface **/
    setfillstyle(1,15);
    bar(x,y,x+deskWidth,y+deskHeight);
    /* Surface Border */
    setcolor(0);
    rectangle(x,y,x+deskWidth,y+deskHeight);
    /* Surface Shadow */
    setcolor(7);
    for(int i=1; i<4; i++)
        line(x+i*2,y+deskHeight+i,x+deskWidth-i*2,y+deskHeight+i);
}

void laptop(int x=384, int y=319)
{
    /* Outer Screen Parameters */
    const int scrWidth = 256;
    const int scrHeight = 187;

    /* Inner Screen Parameters */
    const int innerX = x+5;
    const int innerY = y+5;
    const int innerScrWidth = scrWidth-10;
    const int innerScrHeight = scrHeight-10;

    /* Keyboard Parameters */
    const int keyboardX= x-35;
    const int keyboardY= y+scrHeight;
    const int keyboardWidth = scrWidth+70;
    const int keyboardHeight = 8;

    /** Outer Screen **/
    setfillstyle(1,0);
    bar(x,y,x+scrWidth,y+scrHeight);

     /** Inner Screen **/
    setfillstyle(1,3);
    bar(innerX,innerY,innerX+innerScrWidth,innerY+innerScrHeight);

    /** Keyboard Screen **/
    setfillstyle(1,15);
    bar(keyboardX,keyboardY,keyboardX+keyboardWidth,keyboardY+keyboardHeight);
    /* Keyboard Shadow */
    setcolor(4);
    for(int i=0; i<6; i++)
        line(keyboardX+i*2,keyboardY+keyboardHeight+i,keyboardX+keyboardWidth-i*2,keyboardY+keyboardHeight+i);

}

void lamp(int X = 780, int Y = 507)
{
    struct Stand
    {
        const int x;
        const int y;
        const int width;
        const int height;
    };

    Stand stand = {X,Y,75,10};
    /** Lamp Stand **/
    setfillstyle(1,0);
    bar(stand.x,stand.y,stand.x+stand.width,stand.y+stand.height);
    /* stand - round corners */
    setcolor(0);
    circle(stand.x,stand.y+stand.height/2,stand.height/2); // corner 1
    floodfill(stand.x-1,stand.y+stand.height/2,0);
    circle(stand.x+stand.width,stand.y+stand.height/2,stand.height/2); //corner 2
    floodfill(stand.x+stand.width+1,stand.y+stand.height/2,0);

    /** Lamp supporter **/
    for(int i=0;i<3;i++)
    {
        line(stand.x+stand.width/2+i, stand.y, stand.x + stand.width/2+i, stand.y-10); //LmpS1

        line(stand.x+stand.width/2-10, stand.y-10+i, stand.x + stand.width/2+10, stand.y-10+i);//LmpS2

        line(stand.x+stand.width/2-10+5+i, stand.y-10+i, stand.x+stand.width+i, stand.y-100+i); //LmpS3
        line(stand.x+stand.width/2+10-5+i, stand.y-10+i, stand.x+stand.width+10+i, stand.y-100+i);//LmpS3

        line(stand.x+stand.width-5, stand.y-100+i, stand.x+stand.width+10+5, stand.y-100+i);//LmpS4
    }

    setlinestyle(0,0,3);
    line(stand.x+stand.width+5, stand.y-100, stand.x+stand.width/2-20, stand.y-180); //LmpS5

    /** Lamp Cover **/
    int lampCover[] = {
        stand.x+stand.width/2-20-10, stand.y-180+10,                        // c1
        stand.x+stand.width/2-20+10, stand.y-180-10,                        // c2
        stand.x+stand.width/2-20+10-20, stand.y-180-10-20,                  // c3
        stand.x+stand.width/2-20+10-20-20, stand.y-180-10-20+20,            // c4
        stand.x+stand.width/2-20+10-20-20-30, stand.y-180-10-20+20,         // c5
        stand.x+stand.width/2-20+10-20-20-30+50, stand.y-180-10-20+20+50,   // c6
        stand.x+stand.width/2-20-10, stand.y-180+10                         // c1
    };
    setfillstyle(1,8);
    fillpoly(7,lampCover);

    /** Lamp Light **/
    const int lightX =stand.x+stand.width/2-20+10-20-20-30 + 25; // x = (c5+c6)/2
    const int lightY =stand.y-180-10-20+20 + 25; // y = (c5+c6)/2

    /**--> Light off <--**/
    setfillstyle(1,15);
    ellipse(lightX, lightY,135+10,270+45-10,20,20);
    floodfill(lightX-2,lightY+2,0);
    /* Border */
    setcolor(15);
    ellipse(lightX, lightY,135+10,270+45-10,20,20);

    //getch();

    /**--> Light on <--**/

    setfillstyle(1,14);
    setcolor(0);
    arc(lightX, lightY,135+10,270+45-10,20);
    floodfill(lightX-2,lightY+2,0);
     /**----> Light on Animation <----**/
    setlinestyle(0,0,1);
    int color = 14;
    for(int j=1;j<=5;j++)
    {
        setcolor(color);
        for(int i=5;i<25;i+=5)
        {
            delay(100);
            arc(lightX, lightY,135+10,270+45-10,20+i);
        }
        color = (color==14)?12 : 14;
    }

}
void note(int x=384+40, int y=317-80, int color=3)
{
    const int width = 70;
    const int height = 50;

    setfillstyle(1,color);
    bar(x,y,x+width,y+height);

    setfillstyle(1,15);
    bar(x+5,y+10,x+5+50,y+10+5);
    bar(x+5,y+10+10,x+5+50,y+10+10+5);
    bar(x+5,y+10+10+10,x+5+30,y+10+10+10+5);

    int corner[] = {
       x+width,y+height-15,
       x+width-15,y+height-15,
       x+width-15,y+height,
       x+width,y+height-15,
    };
    int nonCorner[] = {
       x+width,y+height,
       x+width,y+height-15,
       x+width-15,y+height,
       x+width,y+height,
    };
    setfillstyle(1,15);
    fillpoly(4,corner);
    setcolor(3);
    drawpoly(4,corner);

     setfillstyle(1,12);
    fillpoly(4,nonCorner);
    setcolor(12);
    drawpoly(4,nonCorner);
}
void photo(int x, int y)
{
    const int height = 60;
    const int width = 70;
    setfillstyle(1,8);
    bar(x+2, y+2, x+width+2, y+height+2);
    setfillstyle(1,15);
    bar(x, y, x+width, y+height);
    setfillstyle(1,1);
    bar(x+10,y+10,x+width-10,y+height-15);
    setcolor(0);
    circle(x+width/2,y,4);
    setfillstyle(1,0);
    floodfill(x+width/2,y-2,0);
}

void watch(int x,int y)
{
    int r = 80;
    setfillstyle(1,0);
    fillellipse(x,y,r,r);
    setfillstyle(1,15);
    fillellipse(x,y,r-5,r-5);
    setfillstyle(1,0);
    fillellipse(x,y,5,5);


    setlinestyle(0,0,3);
    setcolor(0);
    line(x,y,x,y-r+20);
    line(x,y,x+r-40,y);
}
void book(int bookX, int bookY, int color,bool reflected = false)
{
    setfillstyle(1,color);
    const int bookHeight = 20;
    const int bookWidth = 120;
    bar(bookX,bookY,bookX+bookWidth,bookY+bookHeight);
    setfillstyle(1,15);
    if(reflected)
        bar(bookX,bookY+3,bookX+bookWidth-5,bookY+bookHeight-3);
    else
        bar(bookX+5,bookY+3,bookX+bookWidth,bookY+bookHeight-3);
}

void bookshelf(int x, int y)
{
    const int width = 300;
    const int height = 15;
    const int bookX = x+120;
    const int bookY = y-20;

    /** Bookshelf Stand **/
    setfillstyle(1,8);//shadow
    bar(x+2,y+2,x+width+2,y+height+2);
    setfillstyle(1,15);
    bar(x,y,x+width,y+height);

    /** BOOKS **/
    book(bookX,bookY,4);
    book(bookX-20,bookY-20,6);
    book(bookX+25,bookY-40,3,true);
    book(bookX-25,bookY-60,1);

    /** Directory **/
    const int directoryX = bookX-25+2;
    const int directoryY = bookY-60-4;
    int directory[] = {
        directoryX,directoryY,
        directoryX-30,directoryY-15,
        directoryX-30-40,directoryY-15+80,
        directoryX-30-40+30,directoryY-15+80+15,
        directoryX,directoryY
    };
    int innerDirectory[] = {
        directoryX-10,directoryY+5,
        directoryX-30,directoryY-15+10,
        directoryX-30-20,directoryY-15+11+40,
        directoryX-30-20+20,directoryY-15+11+40+10,
        directoryX-10,directoryY+7,
    };
    setfillstyle(1,3);
    setcolor(3);
    setlinestyle(0,0,3);
    fillpoly(5,directory);

    setfillstyle(1,15);
    setcolor(15);
    setlinestyle(0,0,1);
    fillpoly(5,innerDirectory);
     setlinestyle(0,0,3);
    line(directoryX-30-20-5,directoryY-15+11+40+10,directoryX-30-20+20-5,directoryY-15+11+40+10+10);
    line(directoryX-30-20-10,directoryY-15+11+40+20,directoryX-30-20+20-10,directoryY-15+11+40+10+20);

}
void frame(int x,int y,int color,float scaleX=1,float scaleY=1)
{
    const int width = (int)70*scaleX;
    const int height = (int)90*scaleY;
    setfillstyle(1,0);
    bar(x,y,x+width,y+height);
    setfillstyle(1,color);
    bar(x+5,y+5,x+width-5,y+height-5);

    setlinestyle(0,0,1);
    setcolor(0);
    setfillstyle(1,0);
    fillellipse(x+width/2, y-width/4,4,4);

    int holder[] = {
        x+width/2, y-width/4,
        x+width/4,y,
        x+width-width/4,y,
        x+width/2, y-width/4,
    };
    setlinestyle(0,0,2);
    drawpoly(4,holder);


}
void frameSet()
{
    frame(100,100,3);
    frame(80,265,2,3,1.4);
    frame(getmaxx()-180,150,9,1.2,1.2);
    frame(getmaxx()-80,250,3,0.8,0.8);

}
int main()
{
    CustomGraphics cg1;
    cout<<cg1.isWorking();
    int gd=6, gm=1;
    initgraph(&gd, &gm,"");
    background();
    const int deskX = 72, deskY = 517;
    const int laptopX = deskX + 312, laptopY = deskY - 200;
    const int lampX = deskX + 708, lampY = deskY - 10;
    const int noteX = laptopX+40, noteY = laptopY-85;
    int delayTime = 200;

    setbkcolor(12);
    setcolor(0);
    settextstyle(10, HORIZ_DIR, 5);
    outtextxy(getmaxx()/4+50,getmaxy()/2-50,"Press any key...");
    animatedRectangle(getmaxx()/4+50-20,getmaxy()/2-50-20,getmaxx()/4+50+450,getmaxy()/2-50+50,.2,0);

    getch();
    cleardevice();

    delay(delayTime);
    desk(deskX,deskY);
    delay(delayTime);
    laptop(laptopX,laptopY);
    delay(delayTime);
    note(noteX,noteY,3);
    delay(delayTime);
    note(noteX+100,noteY+20,4);
    delay(delayTime);
    photo(deskX+40,deskY-100);
    delay(delayTime);
    photo(deskX+90,deskY-80);
    delay(delayTime);
    watch(getmaxx()-350,150);
    delay(delayTime);
    bookshelf(deskX+150, noteY-50);
    delay(delayTime);
    frameSet();
    delay(delayTime);
    lamp(lampX,lampY);

    getch();
    closegraph();
    return 0;
}
