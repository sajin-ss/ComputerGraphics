#include <graphics.h>
#include <iostream>

#define ROUND(a) ((int) a+0.5)

using namespace std;




void lineBresenham(int x1, int y1, int x2, int y2)
{
	int x = x1;
	int y = y1;

	int dx = x2 - x1;
	int dy = y2 - y1;
	int pk = 2*dy - dx;

	putpixel(x, y, 3);
	

	while(x<=x2)
	{
		if (pk < 0)
		{
			x = x + 1;
			y = y;
			pk = pk + 2*dy;
		}
		else
		{
			x = x + 1;
			y = y+1;
			pk = pk + 2*dy - 2*dx;
		}


		putpixel(x, y, 3);
		delay(100);
	}
}

int main()
{

    int gd=DETECT,gm; 
	initgraph(&gd,&gm,NULL);

	int x1, y1, x2, y2;
	cout << endl << "Enter point 1 : ";
	cin >> x1 >> y1;
	cout << endl << "Enter point 2 : ";
	cin >> x2 >> y2;
	if (x1<x2)
		lineBresenham( x1, y1, x2, y2);
	else
		lineBresenham(x2, y2, x1, y1);

	delay(5000);
    closegraph();
	return 0;
}