// create a file name it example.cpp or any other name with .cpp extension
// g++ -o main main.cpp -lbgi -lgdi32 -lcomdlg32 -luuid -loleaut32 -lole32

#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int clicks[100][2];
int ind = 0;

void click_handler(int x, int y)
{
    printf("\n{%d,%d}\n", x, y);
    clicks[ind][0] = x;
    clicks[ind][1] = y;
    ind++;
}

void Line(int x1, int y1, int x2, int y2, int color = YELLOW)
{

    int xfark = x2 - x1;
    int yfark = y2 - y1;
    float m = float(yfark) / float(xfark);
    // denklem m*(x2-x1)=y2-y1;
    // y2=m*(x2-x1)+y1;
    // x2=((y2-y1)/m)+x1;

    if (abs(xfark) >= abs(yfark))
    {
        if (xfark >= 0)
        {
            for (int i = x1; i <= x2; i++)
            {
                y2 = (m * (i - x1)) + y1;
                putpixel(i, y2, color);
            }
        }
        else
        {
            for (int i = x2; i <= x1; i++)
            {
                y2 = (m * (i - x1)) + y1;
                putpixel(i, y2, color);
            }
        }
    }
    else
    {
        if (yfark >= 0)
        {
            for (int i = y1; i <= y2; i++)
            {
                x2 = ((i - y1) / m) + x1;
                putpixel(x2, i, color);
            }
        }
        else
        {
            for (int i = y2; i <= y1; i++)
            {
                x1 = ((i - y2) / m) + x2;
                putpixel(x1, i, color);
            }
        }
    }
}

void Triangle()
{
    int x1 = clicks[ind - 3][0];
    int x2 = clicks[ind - 2][0];
    int x3 = clicks[ind - 1][0];
    int y1 = clicks[ind - 3][1];
    int y2 = clicks[ind - 2][1];
    int y3 = clicks[ind - 1][1];

    // denklem m*(x2-x1)=y2-y1;
    // y2=m*(x2-x1)+y1;
    // x2=((y2-y1)/m)+x1;

    Line(x3, y3, x2, y2, RED);
    Line(x2, y2, x1, y1, RED);
    Line(x1, y1, x3, y3, RED);
}

void Square()
{
    int x1 = clicks[ind - 1][0];
    int y1 = clicks[ind - 1][1];

    int a = rand() % 300;
    int x2 = x1 + a;
    int y2 = y1;
    int x3 = x1 + a;
    int y3 = y1 + a;
    int x4 = x1;
    int y4 = y1 + a;

    Line(x1, y1, x2, y2, BLUE);
    Line(x2, y2, x3, y3, BLUE);
    Line(x3, y3, x4, y4, BLUE);
    Line(x4, y4, x1, y1, BLUE);
}

void fullSquare()
{
    int x1 = clicks[ind - 1][0];
    int y1 = clicks[ind - 1][1];

    int a = rand() % 300;
    int x2 = x1 + a;
    int y2 = y1;
    int x3 = x1 + a;
    int y3 = y1 + a;
    int x4 = x1;
    int y4 = y1 + a;

    for (int i = x1; i <= x3; i++)
    {
        for (int j = y1; j < y3; j++)
        {
            putpixel(i, j, BLUE);
        }
    }
}

void Rectangle()
{
    int x1 = clicks[ind - 1][0];
    int y1 = clicks[ind - 1][1];

    int a = rand() % 300;
    int b = rand() % 300;
    int x2 = x1 + b;
    int y2 = y1;
    int x3 = x1 + b;
    int y3 = y1 + a;
    int x4 = x1;
    int y4 = y1 + a;

    Line(x1, y1, x2, y2, GREEN);
    Line(x2, y2, x3, y3, GREEN);
    Line(x3, y3, x4, y4, GREEN);
    Line(x4, y4, x1, y1, GREEN);
}

void fullRectangle()
{
    int x1 = clicks[ind - 1][0];
    int y1 = clicks[ind - 1][1];

    int a = rand() % 300;
    int b = rand() % 300;
    int x2 = x1 + b;
    int y2 = y1;
    int x3 = x1 + b;
    int y3 = y1 + a;
    int x4 = x1;
    int y4 = y1 + a;

    for (int i = x1; i <= x3; i++)
    {
        for (int j = y1; j < y3; j++)
        {
            putpixel(i, j, GREEN);
        }
    }
}

void Circle(int xm, int ym, int r)
{
    int derece;
    for (derece = 0; derece < 360; derece++)
    {
        double radyan = (derece * M_PI) / 180.0;
        double x = xm + (r * cos(radyan));
        double y = ym + (r * sin(radyan));
        putpixel(x, y, MAGENTA);
    }
}

void fullCircle(int xm, int ym, int r)
{
    float c = rand();
    for (int i = -r; i <= r; i++)
    {
        for (int j = -r; j <= r; j++)
        {
            if (((i * i) + (j * j)) < (r * r))
            {
                putpixel(i + xm, j + ym, c);
            }
        }
    }
}

void Ellipse(int xm, int ym, int r1, int r2)
{
    int derece;
    for (derece = 0; derece < 360; derece++)
    {
        double radyan = (derece * M_PI) / 180.0;
        double x = xm + (r1 * cos(radyan));
        double y = ym + (r2 * sin(radyan));
        putpixel(x, y, LIGHTBLUE);
    }
}

void fullEllipse(int xm, int ym, int r1, int r2)
{
    for (int i = -r1; i <= r1; i++)
    {
        for (int j = -r2; j <= r2; j++)
        {
            if ((((i * i) * (r2 * r2)) + ((j * j) * (r1 * r1))) < (r1 * r1) * (r2 * r2))
            {
                putpixel(i + xm, j + ym, LIGHTBLUE);
            }
        }
    }
}

void Arc(int xm, int ym, int r)
{
    int derece;
    int dereceW = rand() % 360 + 1;
    for (derece = 0; derece < dereceW; derece++)
    {
        double radyan = (derece * M_PI) / 180.0;
        double x = xm + (r * cos(radyan));
        double y = ym + (r * sin(radyan));
        putpixel(x, y, LIGHTMAGENTA);
    }
}

void Disc(int xm, int ym, int r1, int r2)
{
    for (int i = -r2; i <= r2; i++)
    {
        for (int j = -r2; j <= r2; j++)
        {
            if (((i * i) + (j * j)) < (r2 * r2) && ((i * i) + (j * j)) > (r1 * r1))
            {
                putpixel(i + xm, j + ym, CYAN);
            }
        }
    }
}

void Stars()
{
    int x1 = clicks[ind - 1][0];
    int y1 = clicks[ind - 1][1];

    int x2 = x1 + 200;
    int y2 = y1;
    int x3 = x1 + 40;
    int y3 = y1 + 80;
    int x4 = x1 + 110;
    int y4 = y1 - 40;
    int x5 = x1 + 160;
    int y5 = y1 + 80;

    Line(x1, y1, x2, y2, MAGENTA);
    Line(x2, y2, x3, y3, MAGENTA);
    Line(x3, y3, x4, y4, MAGENTA);
    Line(x4, y4, x5, y5, MAGENTA);
    Line(x5, y5, x1, y1, MAGENTA);
}

void Polygon()
{
    int x1 = clicks[ind - 6][0];
    int x2 = clicks[ind - 5][0];
    int x3 = clicks[ind - 4][0];
    int x4 = clicks[ind - 3][0];
    int x5 = clicks[ind - 2][0];
    int x6 = clicks[ind - 1][0];
    int y1 = clicks[ind - 6][1];
    int y2 = clicks[ind - 5][1];
    int y3 = clicks[ind - 4][1];
    int y4 = clicks[ind - 3][1];
    int y5 = clicks[ind - 2][1];
    int y6 = clicks[ind - 1][1];

    Line(x1, y1, x2, y2, RED);
    Line(x2, y2, x3, y3, RED);
    Line(x3, y3, x4, y4, RED);
    Line(x4, y4, x5, y5, RED);
    Line(x5, y5, x6, y6, RED);
    Line(x6, y6, x1, y1, RED);
}

void Crop()
{
    int x1 = clicks[ind - 2][0];
    int x3 = clicks[ind - 1][0];
    int y1 = clicks[ind - 2][1];
    int y3 = clicks[ind - 1][1];

    int x2 = x3;
    int y2 = y1;
    int x4 = x1;
    int y4 = y3;

    for (int i = 0; i < x1; i++)
    {
        for (int j = 0; j < 600; j++)
        {
            putpixel(i, j, BLACK);
        }
    }

    for (int i = x3; i < 800; i++)
    {
        for (int j = 0; j < 600; j++)
        {
            putpixel(i, j, BLACK);
        }
    }

    for (int i = x1; i < x3; i++)
    {
        for (int j = 0; j < y1; j++)
        {
            putpixel(i, j, BLACK);
        }
    }

    for (int i = x1; i < x3; i++)
    {
        for (int j = y3; j < 600; j++)
        {
            putpixel(i, j, BLACK);
        }
    }
}

void Translation()
{
    int x1 = clicks[ind - 2][0];
    int x2 = clicks[ind - 1][0];
    int y1 = clicks[ind - 2][1];
    int y2 = clicks[ind - 1][1];
    Line(x1, y1, x2, y2);
    Sleep(220);
    int t = 50;
    x1 = x1 + t;
    x2 = x2 + t;
    Line(x1, y1, x2, y2, LIGHTBLUE);
    Sleep(220);
    y1 = y1 + t;
    y2 = y2 + t;
    Line(x1, y1, x2, y2, LIGHTGREEN);
}

void Rotation()
{
    int x1 = clicks[ind - 2][0];
    int x2 = clicks[ind - 1][0];
    int y1 = clicks[ind - 2][1];
    int y2 = clicks[ind - 1][1];
    Line(x1, y1, x2, y2);
    Sleep(220);
    int t = 50;
    x2 = x2 + t;
    Line(x1, y1, x2, y2, LIGHTBLUE);
    Sleep(220);

    y2 = y2 + t;
    Line(x1, y1, x2, y2, LIGHTGREEN);
}

void Scaling()
{
    int x1 = clicks[ind - 1][0];
    int y1 = clicks[ind - 1][1];

    int a = rand() % 300;
    int b = rand() % 300;
    int x2 = x1 + b;
    int y2 = y1;
    int x3 = x1 + b;
    int y3 = y1 + a;
    int x4 = x1;
    int y4 = y1 + a;

    Line(x1, y1, x2, y2, GREEN);
    Line(x2, y2, x3, y3, GREEN);
    Line(x3, y3, x4, y4, GREEN);
    Line(x4, y4, x1, y1, GREEN);
    Sleep(200);

    int c = a / 2;
    int d = b / 2;
    x1 = x1 + (x2 - x1) + 10;
    x2 = x1 + d;
    y2 = y1;
    x3 = x1 + d;
    y3 = y1 + c;
    x4 = x1;
    y4 = y1 + c;

    Line(x1, y1, x2, y2, GREEN);
    Line(x2, y2, x3, y3, GREEN);
    Line(x3, y3, x4, y4, GREEN);
    Line(x4, y4, x1, y1, GREEN);
}

int main()
{

    int IdW1 = initwindow(400, 400, "INFO", 801);
    setcurrentwindow(IdW1);

    outtextxy(0, 0, "Q-->QUIT");
    outtextxy(0, 20, "L-->LINE");
    outtextxy(0, 40, "T-->TRIANGLE");
    outtextxy(0, 60, "S-->SQUARE");
    outtextxy(0, 80, "1-->FULL SQUARE");
    outtextxy(0, 100, "R-->RECTANGLE");
    outtextxy(0, 120, "2-->FULL RECTANGLE");
    outtextxy(0, 140, "C-->CIRCLE");
    outtextxy(0, 160, "3-->FULL CIRCLE");
    outtextxy(0, 180, "E-->ELLIPSE");
    outtextxy(0, 200, "4-->FULL ELLIPSE");
    outtextxy(0, 220, "A-->ARC");
    outtextxy(0, 240, "D-->DISC");
    outtextxy(0, 260, "Y-->STAR");
    outtextxy(0, 280, "P-->POLYGON");
    outtextxy(0, 300, "5-->CROP");
    outtextxy(0, 320, "6-->TRANSLATION");
    outtextxy(0, 340, "7-->ROTATION");
    outtextxy(0, 360, "8-->SCALING");
    outtextxy(0, 380, "0-->CLEAN");

    int IdW2 = initwindow(800, 600, "MAIN");
    setcurrentwindow(IdW2);

    registermousehandler(WM_LBUTTONDOWN, click_handler);

    char cm;
    while (true)
    {
        cm = getch();
        if (cm == 'Q' || cm == 'q')
        {
            break;
        }
        else if (cm == 'L' || cm == 'l')
        {
            int x1 = clicks[ind - 2][0];
            int x2 = clicks[ind - 1][0];
            int y1 = clicks[ind - 2][1];
            int y2 = clicks[ind - 1][1];
            Line(x1, y1, x2, y2);
        }
        else if (cm == 'T' || cm == 't')
        {
            Triangle();
        }
        else if (cm == 'S' || cm == 's')
        {
            Square();
        }
        else if (cm == '1')
        {
            fullSquare();
        }
        else if (cm == 'R' || cm == 'r')
        {
            Rectangle();
        }
        else if (cm == '2')
        {
            fullRectangle();
        }
        else if (cm == 'C' || cm == 'c')
        {
            int xm = clicks[ind - 1][0];
            int ym = clicks[ind - 1][1];
            int r = rand() % 100;
            Circle(xm, ym, r);
        }
        else if (cm == '3')
        {
            int xm = clicks[ind - 1][0];
            int ym = clicks[ind - 1][1];
            int r = rand() % 100;
            fullCircle(xm, ym, r);
        }
        else if (cm == 'E' || cm == 'e')
        {
            int xm = clicks[ind - 1][0];
            int ym = clicks[ind - 1][1];
            int r1 = rand() % 100;
            int r2 = rand() % 150;
            Ellipse(xm, ym, r1, r2);
        }
        else if (cm == '4')
        {
            int xm = clicks[ind - 1][0];
            int ym = clicks[ind - 1][1];
            int r1 = rand() % 100;
            int r2 = rand() % 100;
            fullEllipse(xm, ym, r1, r2);
        }
        else if (cm == 'A' || cm == 'a')
        {
            int xm = clicks[ind - 1][0];
            int ym = clicks[ind - 1][1];
            int r = rand() % 100;
            Arc(xm, ym, r);
        }
        else if (cm == 'D' || cm == 'd')
        {
            int xm = clicks[ind - 1][0];
            int ym = clicks[ind - 1][1];
            int r1 = 35;
            int r2 = 50;
            Disc(xm, ym, r1, r2);
        }
        else if (cm == 'Y' || cm == 'y')
        {
            Stars();
        }
        else if (cm == 'P' || cm == 'p')
        {
            Polygon();
        }
        else if (cm == '5')
        {
            Crop();
        }
        else if (cm == '6')
        {
            Translation();
        }
        else if (cm == '7')
        {
            Rotation();
        }
        else if (cm == '8')
        {
            Scaling();
        }
        else if (cm == '0')
        {
            for (int i = 0; i <= 800; i++)
            {
                for (int j = 0; j < 600; j++)
                {
                    putpixel(i, j, BLACK);
                }
            }
        }
    }

    getch();
    closegraph();
    return 0;
}