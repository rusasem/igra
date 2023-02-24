//========================================================================
#include "TXLib.h"

struct Personage
{
  int x;
  int y;
  HDC image;
  int vx;
  int vy;
};

int main()
{
txCreateWindow (800, 600);

    HDC fon = txLoadImage("картинки/jj.bmp");
    HDC hhh = txLoadImage("картинки/враг.bmp");
    int x = 710;
    HDC hh = txLoadImage("картинки/враг.bmp");
    int t = 710;
    HDC h = txLoadImage("картинки/враг.bmp");
    int y = 30;
    Personage hhh1= {710,270,txLoadImage("картинки/1000-7.bmp"),10,10};
    while(!GetAsyncKeyState(VK_ESCAPE))




    {

    if(GetAsyncKeyState('W'))
   hhh1.y=hhh1.y-10;

    if(GetAsyncKeyState('S'))
   hhh1.y=hhh1.y+10;

    if(GetAsyncKeyState('D'))
   hhh1.x=hhh1.x+10;

    if(GetAsyncKeyState('A'))
   hhh1.x=hhh1.x-10;

    if(hhh1.x==0)
    hhh1.x=hhh1.x+10;

    if(hhh1.y==0)
    hhh1.x=hhh1.y+10;

    if(hhh1.x==800)
    hhh1.x=hhh1.x-10;

    if(hhh1.y==600)
    hhh1.y=hhh1.y-10;


    txSetColor (TX_WHITE);
    txSetFillColor (TX_TRANSPARENT);
    txClear();

    txBegin();
    txBitBlt(txDC(),0,0,800,600,fon);

    txBitBlt(txDC(),hhh1.x,hhh1.y,50,60,hhh1.image);

    txBitBlt(txDC(),t,20,50,60,hh);
    t-=2;
    txBitBlt(txDC(),330,y,50,60,h);
    y+=2;

    txEnd();
    txSleep(10);

    }

txTextCursor (false);
return 0;
}

