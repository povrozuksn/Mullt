#include "TXLib.h"

//Область создание функций
void drawSky(COLORREF color)
{
//RGB(162, 247, 251)
    txSetColor(color);
    txSetFillColor(color);
    txRectangle(0, 0, 800, 600);
}

void drawSun(int x, int y)
{
    txSetColor(RGB(255, 155, 106));
    txSetFillColor(RGB(252, 252, 16));
    txCircle(x, y, 50);
}

void drawLand(COLORREF color)
{
//RGB(140, 255, 140)
    txSetColor(TX_GREEN);
    txSetFillColor(color);
    txRectangle(0, 400, 800, 600);
}

void drawHouse(COLORREF colorWindow)
{
    //крыша
    txSetColor(TX_BROWN);
    txSetFillColor(RGB(128, 0, 0));
    POINT star[3] = {{280, 250}, {410, 120}, {550, 250}};
    txPolygon (star, 3);

    //стена
    txSetColor(TX_RED);
    txSetFillColor(RGB(215, 215, 0));
    txRectangle(280, 250, 550, 500);

//RGB(217, 240, 247)
    //окно
    txSetColor(TX_RED);
    txSetFillColor(colorWindow);
    txRectangle(310, 300, 400, 400);

    //дверь
    txSetColor(TX_RED);
    txSetFillColor(RGB(128, 0, 0));
    txRectangle(430, 330, 520, 500);
    //txCircle();


}

void drawCloud(int x, int y)
{
//80, 70
    txSetColor(RGB(106, 181, 255));
    txSetFillColor(RGB(106, 181, 255));
    txEllipse (x+80-80, y, x+210-80, 140);
    txEllipse (x+170-80, 80, x+300-80, 150);
    txEllipse (x+250-80, 70, x+380-80, 140);
}

void drawMan(int x, int xLegs, int xHands)
{
//x=660
    txSetColor(RGB(255, 210, 166));
    txSetFillColor(RGB(255, 210, 166));
    txCircle(x, 430, 20);               //Голова
    txSetColor(RGB(255, 210, 166), 7);
    txLine(x, 450, x, 520);           //Тело
    txLine(x, 465, x-35+xHands, 490);           //Левая рука
    txLine(x, 465, x+30-xHands, 490);           //Правая рука
    txLine(x, 520, x-20+xLegs, 560);           //Левая нога
    txLine(x, 520, x+20-xLegs, 560);           //Правая нога
}

void drawTree(int x, int y)
{
//x=110 y=485
//Ствол
    txSetColor(TX_BLACK);
    txSetFillColor(TX_BLACK);
    txRectangle(x+110-110, y+310-485, x+125-110, y+485-485);
//Крона
    txSetColor(RGB(0, 100, 0));
    txSetFillColor(RGB(0, 255, 0));
    txEllipse (x+80-110, y+190-485, x+150-110, y+420-485);
}

void drawGrib(double razm)
{

    txSetColor(TX_BLACK);
    txSetFillColor(RGB(185, 122, 87));
    txEllipse (610, 460, 640*razm, 510*razm);

    txSetColor(TX_BLACK);
    txSetFillColor(TX_BLACK);
    txEllipse(600, 430, 660*razm, 470*razm);

}


int main()
{
txCreateWindow (800, 600);

    int xSun = -100;
    int ySun = -100;
    int xCloud = 80;
    int xMan = 660;
    int xManLegs = 0;
    int xManHands = 0;
    double razGrib = 1;

    while (xSun<1000)
    {
        txBegin();
        drawSky(RGB(162, 247, 251));
        drawSun(xSun, ySun);
        drawCloud(xCloud, 70);
        drawLand(RGB(140, 255, 140));
        drawHouse(RGB(217, 240, 247));
        drawTree(110, 485);
        drawTree(190, 450);
        drawTree(30, 450);
        drawGrib(razGrib);
        drawMan(xMan, xManLegs, xManHands);
        txEnd();
        xSun = xSun + 5;
        ySun = ySun + 3;
        xMan = xMan - 3;
        xManLegs = xManLegs + 10;
        xManHands = xManHands + 10;
        razGrib = razGrib + 0.0005;
        txSleep(50);

        txBegin();
        drawSky(RGB(162, 247, 251));
        drawSun(xSun, ySun);
        drawCloud(xCloud, 70);
        drawLand(RGB(140, 255, 140));
        drawHouse(RGB(217, 240, 247));
        drawTree(110, 485);
        drawTree(190, 450);
        drawTree(30, 450);
        drawGrib(razGrib);
        drawMan(xMan, xManLegs, xManHands);
        txEnd();
        xSun = xSun + 5;
        ySun = ySun + 3;
        xMan = xMan - 3;
        xManLegs = xManLegs - 10;
        xManHands = xManHands - 10;
        razGrib = razGrib + 0.0005;
        txSleep(50);
    }

    while (xCloud<1000)
    {
        txBegin();
        drawSky(RGB(64, 0, 128));
        drawSun(xSun, 100);
        drawCloud(xCloud, 70);
        drawLand(RGB(0, 64, 0));
        drawHouse(RGB(255, 255, 0));
        drawTree(110, 485);
        drawTree(190, 450);
        drawTree(30, 450);
        drawMan(xMan, xManLegs, xManHands);
        txEnd();

        xCloud = xCloud + 1;
        txSleep(10);
    }


txTextCursor (false);
return 0;
}

