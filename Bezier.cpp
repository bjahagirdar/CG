#include<graphics.h>
#include<math.h>
#include<iostream>
using namespace std;

int Bezier(int x[4],int y[4])
{
	double u;
	
	
	for(u=0.0;u<1.0;u=u+0.005)
	{
		double xt = pow(1-u,3) * x[0] + 3 * u * pow(1-u,2) * x[1] + 3 * pow(u,2) * (1-u) * x[2] + pow(u,3) * x[3];
		
		double yt = pow(1-u,3) * y[0] + 3 * u * pow(1-u,2) * y[1] + 3 * pow(u,2) * (1-u) * y[2] + pow(u,3) * y[3];
		
		putpixel(xt,yt,YELLOW);
		delay(50);
	}
	delay(10000);
	//closegraph();
	return 0;
}

void flower()
{
	int x1[4] = { 200,160,240,200},	y1[4] = {200,160,160,200};
	int x2[4] = {200,240,240,200},	y2[4] = {200,160,240,200};
	int x3[4] = {200,240,160,200},	y3[4] = {200,240,240,200};
	int x4[4] = {200,160,160,200},	y4[4] = {200,240,160,200};
	
	Bezier(x1,y1);
	Bezier(x2,y2);
	Bezier(x3,y3);
	Bezier(x4,y4);
	
	setcolor(YELLOW);
	line(200,230,200,300);
	delay(1000);
	closegraph();
	getch();
}
int main()
{
	int op;
	int gd=DETECT,gm;
	cout<<"\nEnter\n1 - Bezier curve.\n2 - Flower.\n";
	cin>>op;
	switch(op)
	{
		case 1:
				int x[4],y[4];
				cout<<"\nEnter the Control Points : ";
				for(int i=0;i<4;i++)
				{
					cin>>x[i]>>y[i];
				}
		
				initgraph(&gd,&gm,NULL);
				Bezier(x,y);
				closegraph();
				break;
				
		case 2:
				initgraph(&gd,&gm,NULL);
				flower();
				closegraph();
				break;
		default:
				cout<<"\nINVALID ENTRY!!!";	
	}
	return 0;
}
