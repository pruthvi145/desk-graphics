#include <graphics.h>
#include<iostream>

using namespace std;

/** COLORS **/

struct Color { int r,g,b; };

Color white = {255,255,255};
Color desk_space = {238,239,240};
Color bg = {243,205,162};
Color lap_outscr = {23,40,53};
Color lap_innscr = {0,204,167};
Color lap_keyboard = {246,240,223};
Color lap_shadow = {77,31,18};
Color frame_out = lap_outscr;
Color frame_1 = {246,109,102};
Color frame_2 = frame_1;
Color frame_3 = lap_innscr;
Color frame_4 = frame_3;
Color book_1 = lap_innscr;
Color book_2 = {247,151,91};
Color book_3 = book_1;
Color book_4 = {247,151,91};

/**COLORS-END**/

/** Structures **/

struct Ract { int x,y,width,height; };
struct Bar  { int x,y,width,height; Color color; };
struct Poly { int points[100], n; Color color; };

/** Structures-END **/

void background()
{
    setfillstyle(1,COLOR(bg.r,bg.g,bg.b));
    floodfill(0,0,15);
}

void desk(int x=72, int y=517)
{
    Bar surface = {x, y, 880, 50, white};
    Bar leg1 = {surface.x+70, surface.y+surface.height, 45, 200, white};
    Bar leg2 = {surface.x+surface.width-leg1.width-70, surface.y+surface.height, leg1.width, leg1.height, white};
    Bar space = {leg1.x+leg1.width, leg1.y, surface.width-leg1.width-leg2.width-140, leg1.height, desk_space};

    /** Space **/
    setfillstyle(1, COLOR(space.color.r, space.color.g, space.color.b));
     bar(space.x,space.y,space.x+space.width,space.y+space.height);

    /** Legs **/
    setfillstyle(1, COLOR(leg1.color.r, leg1.color.g, leg1.color.b));
    bar(leg1.x,leg1.y,leg1.x+leg1.width,leg1.y+leg1.height);
    bar(leg2.x,leg2.y,leg2.x+leg2.width,leg2.y+leg2.height);

    /** Surface **/
    setfillstyle(1,COLOR(surface.color.r, surface.color.g, surface.color.b));
    bar(surface.x,surface.y,surface.x+surface.width,surface.y+surface.height);
    /* Surface Border */
    setcolor(0);
    rectangle(surface.x,surface.y,surface.x+surface.width,surface.y+surface.height);
    /* Surface Shadow */
    setcolor(7);
    for(int i=1; i<4; i++)
        line(surface.x+i*2,surface.y+surface.height+i,surface.x+surface.width-i*2,surface.y+surface.height+i);
}

void laptop(int x=384, int y=319)
{
    Bar outscr = {x, y, 256, 187, lap_outscr};
    Bar innscr = {outscr.x+5, outscr.y+5, outscr.width-10, outscr.height-10, lap_innscr};
    Bar keyboard = {outscr.x-35, outscr.y+outscr.height, outscr.width+70,8, lap_keyboard };

    /** Outer Screen **/
    setfillstyle(1,COLOR(outscr.color.r,outscr.color.g,outscr.color.b));
    bar(outscr.x,outscr.y,outscr.x+outscr.width,outscr.y+outscr.height);

     /** Inner Screen **/
    setfillstyle(1,COLOR(lap_innscr.r,lap_innscr.g,lap_innscr.b));
    bar(innscr.x,innscr.y,innscr.x+innscr.width,innscr.y+innscr.height);

    /** Keyboard Screen **/
    setfillstyle(1,COLOR(lap_keyboard.r,lap_keyboard.g,lap_keyboard.b));
    bar(keyboard.x,keyboard.y,keyboard.x+keyboard.width,keyboard.y+keyboard.height);

    /* Keyboard Shadow */
    setcolor(COLOR(lap_shadow.r,lap_shadow.g,lap_shadow.b));
    for(int i=0; i<6; i++)
        line(keyboard.x+i*2, keyboard.y+keyboard.height+i, keyboard.x+keyboard.width-i*2, keyboard.y+keyboard.height+i);

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
    setfillstyle(1,COLOR(23,40,50));
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

    getch();

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
void book(int x, int y, Color color,bool reflected = false)
{
    Bar book = {x, y, 120, 20, color};

    setfillstyle(1,COLOR(book.color.r,book.color.g,book.color.b));
    bar(book.x, book.y, book.x+book.width, book.y+book.height);

    setfillstyle(1,COLOR(white.r,white.g,white.b));
    if(reflected)
        bar(book.x,book.y+3,book.x+book.width-5,book.y+book.height-3);
    else
        bar(book.x+5,book.y+3,book.x+book.width,book.y+book.height-3);
}

void directory(int x, int y, Color color, float angle = 0)
{

    Bar outbook = {x,y,30,80};

    setfillstyle(1,COLOR(color.r,color.g,color.b));
    bar(outbook.x, outbook.y, outbook.x+outbook.width, outbook.y-outbook.height);

    setfillstyle(1,COLOR(white.r,white.g,white.b));
    bar(outbook.x+5, outbook.y-25, outbook.x+outbook.width-5, outbook.y-outbook.height+5);
    setcolor(COLOR(white.r,white.g,white.b));
    setlinestyle(0,0,3);
    line(outbook.x+6, outbook.y-18,outbook.x+outbook.width-6, outbook.y-18);
    line(outbook.x+6, outbook.y-10,outbook.x+outbook.width-6, outbook.y-10);
}

void bookshelf(int x, int y)
{
    Bar stand = {x,y,300,15};
    const int bookX = x+120;
    const int bookY = y-20;

    /** Bookshelf Stand **/
    setfillstyle(1,8);//shadow
    bar(stand.x+2,stand.y+2,stand.x+stand.width+2,stand.y+stand.height+2);

    setfillstyle(1,COLOR(white.r,white.g,white.b));
    bar(stand.x,stand.y,stand.x+stand.width,stand.y+stand.height);

    /** BOOKS **/
    book(bookX,bookY,book_1);
    book(bookX-20,bookY-20,book_2);
    book(bookX+25,bookY-40,book_3,true);
    book(bookX-25,bookY-60,book_4);

    //directory(stand.x+20,stand.y,book_1);

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

void frame(int x, int y, Color color, float scaleX=1, float scaleY=1)
{
    Bar outframe = {x,y,(int)70*scaleX, (int)90*scaleY, frame_out};
    Bar innframe = {outframe.x+5, outframe.y+5, outframe.width-10,outframe.height-10, color};

    Poly hanger = {{
        outframe.x+outframe.width/2, outframe.y-outframe.width/4,
        outframe.x+outframe.width/4,outframe.y,
        outframe.x+outframe.width-outframe.width/4,outframe.y,
        outframe.x+outframe.width/2, outframe.y-outframe.width/4
    },4};

    /** Outer Frame **/
    setfillstyle(1,COLOR(outframe.color.r,outframe.color.g,outframe.color.b));
    bar(outframe.x,outframe.y,outframe.x+outframe.width,outframe.y+outframe.height);

    /** Hanger **/
    setcolor(COLOR(outframe.color.r,outframe.color.g,outframe.color.b));
    fillellipse(outframe.x+outframe.width/2, outframe.y-outframe.width/4,4,4);
    drawpoly(hanger.n,hanger.points);

    /** Inner Frame **/
    setfillstyle(1,COLOR(innframe.color.r,innframe.color.g,innframe.color.b));
    bar(innframe.x,innframe.y,innframe.x+innframe.width,innframe.y+innframe.height);
}
void frameSet()
{
    frame(80,265,frame_1,3,1.4); //1
    frame(getmaxx()-180,150,frame_2,1.2,1.2); //2
    frame(100,100,frame_3); //3
    frame(getmaxx()-80,250,frame_4,0.8,0.8); //4
}
int main()
{

    int gd=6, gm=1;
    initgraph(&gd, &gm,"");
    background();
    const int deskX = 72, deskY = 517;
    const int laptopX = deskX + 312, laptopY = deskY - 200;
    const int lampX = deskX + 708, lampY = deskY - 10;
    const int noteX = laptopX+40, noteY = laptopY-85;
    int delayTime = 200;

    setbkcolor(COLOR(bg.r,bg.g,bg.b));

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
