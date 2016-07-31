#include <graphics.h>
#include <iostream>


void mpcircle(int xc, int yc, int r)
{
	int x=0;
	int y=r;
	int p=1-r;

	while(x<=y)
	{
		putpixel(xc + x, yc + y, 1);
		putpixel(xc + x, yc - y, 1);
		putpixel(xc - x, yc + y, 1);
		putpixel(xc - x, yc - y, 1);

		putpixel(xc + y, yc + x, 1);
		putpixel(xc + y, yc - x, 1);
		putpixel(xc - y, yc + x, 1);
		putpixel(xc - y, yc - x, 1);

		if (p<0)
			p = p + 2*x + 1;
		else
		{
			p = p + 2*(x-y) + 1;
			y = y-1;
		}
		x = x + 1;
	}
}

using namespace std;
int main()
{

    int gd=DETECT,gm; 
	initgraph(&gd,&gm,NULL);

	int xc, yc, r;
	cin >> xc >> yc >> r;
	mpcircle(xc, yc, r);	
	delay(5000);
    closegraph();
	return 0;
}