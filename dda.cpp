#include <graphics.h>
#include <iostream>

#define ROUND(a) ((int) a+0.5)

using namespace std;

void lineDDA(float x1, float y1, float x2, float y2)
{
	int steps;
	float xInc, yInc;

	float x = x1;
	float y = y1;

	float dx = x2 - x1;
	float dy = y2 - y1;

	if (abs(dx) > abs(dy))
		steps = abs(dx);
	else
		steps = abs(dy);
 
	xInc = dx / (float) steps;
	yInc = dy / (float) steps;

	putpixel(ROUND(x), ROUND(y), 1);
	

	for (int k=0; k<steps; ++k)
	{
		x += xInc;
		y += yInc;
		putpixel(ROUND(x), ROUND(y), 1);
		delay(100);
	}
}

int main()
{

    int gd=DETECT,gm; 
	initgraph(&gd,&gm,NULL);

	float x1, y1, x2, y2;
	cout << endl << "Enter point 1 : ";
	cin >> x1 >> y1;
	cout << endl << "Enter point 2 : ";
	cin >> x2 >> y2;
	lineDDA( x1, y1, x2, y2);

	delay(5000);
    closegraph();
	return 0;
}