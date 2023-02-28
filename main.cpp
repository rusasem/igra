
#include "TXLib.h"

 struct Lkl
{
  int x;
  int y;
  HDC image;
  int vx;
  int vy;
};

int main()
    {
    txCreateWindow (800,600);

    int x1_old;
    int y1_old;


    HDC  background = txLoadImage ("fon.bmp");

    Lkl lkl = {10, 30, txLoadImage("lkl.bmp"), 10, 10};
    Lkl gg =  {300, 300, txLoadImage("gg.bmp"), 5, 5};
    Lkl cc =  {700, 300, gg.image, 5, 5};

    COLORREF color;

    char str[100];

    while (!GetAsyncKeyState (VK_ESCAPE))
    {
      txClear();

      txBegin();
      x1_old = lkl.x;
      y1_old = lkl.y;
      txBitBlt (txDC(), 0, 0, 800,600,background);
      txBitBlt (txDC(), lkl.x, lkl.y, 50, 52, lkl.image);
      txBitBlt (txDC(), gg.x, gg.y, 80, 82, gg.image);
      txBitBlt (txDC(), cc.x, cc.y, 80, 82, cc.image);


       if(GetAsyncKeyState('W'))
      {
        lkl.y=lkl.y-lkl.vy;
      }

      if(GetAsyncKeyState('S'))
      {
        lkl.y=lkl.y+lkl.vy;
      }

      if(GetAsyncKeyState('A'))
      {
        lkl.x=lkl.x-lkl.vx;
      }

      if(GetAsyncKeyState('D'))
      {
        lkl.x=lkl.x+lkl.vx;
      }

     for(int x=lkl.x; x<lkl.x+50; x++)
     {
        for(int y=lkl.y; y<lkl.y+52; y++)
        {
            if(txGetPixel(x-1, y-1, txDC()) == RGB(255, 0, 0))
            {
                lkl.x=x1_old;
                lkl.y=y1_old;
            }
        }
     }




      gg.y=gg.y+gg.vy;

      if(gg.y<0 || gg.y>600)
      {
        gg.vy=-gg.vy;
      }


      cc.x=cc.x+cc.vx;

      if(cc.x<700 || cc.x>800)
      {
        cc.vx=-cc.vx;
      }

      /*
      txSetColor(TX_BLACK, 3);
      sprintf(str, "x= %d y= %d", x1, y1);
      txTextOut(510, 10, str);
      */


      txEnd();

      txSleep(10);
    }
    txDeleteDC (background);
    txDeleteDC (lkl.image);
    txDeleteDC (gg.image);
    txDeleteDC (cc.image);

txTextCursor (false);
txDisableAutoPause();
return 0;
}

