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
    //Personage hhh1= 710,270,txLoadImage("картинки/враг.bmp");
    while(!GetAsyncKeyState(VK_ESCAPE))
    {
    txSetColor (TX_WHITE);
    txSetFillColor (TX_TRANSPARENT);
    txClear();

    txBegin();
    txBitBlt(txDC(),0,0,800,600,fon);

    txBitBlt(txDC(),x,270,50,60,hhh);
    x-=22;
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

