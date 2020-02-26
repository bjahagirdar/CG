#include<graphics.h>
#include<iostream>
using namespace std;

int main()
{
int gd=DETECT,gm;
float x,y,shx,shy;
cout<<"Enter x shear";
cin>>shx;
initgraph(&gd,&gm,NULL);
float x1,y1,x2,y2,x3,y3,x4,y4;
x1=10,y1=10,x2=50,y2=10,x3=50,y3=50,x4=10,y4=50;
void dda_line(float,float,float,float);

dda_line(x1,y1,x2,y2);
dda_line(x2,y2,x3,y3);
dda_line(x4,y4,x3,y3);
dda_line(x1,y1,x4,y4);

dda_line(x1+shx*(y1),y1,x2+shx*(y2),y2);
dda_line(x2+shx*(y2),y2,x3+shx*(y3),y3);
dda_line(x4+shx*(y4),y4,x3+shx*(y3),y3);
dda_line(x1+shx*(y1),y1,x4+shx*(y4),y4);



getch();
delay(500);
closegraph();
}

void dda_line(float x1,float y1,float x2,float y2)
{
int i;
float x,y;
float dx,dy,length;

dx=x2-x1;
dy=y2-y1;
	if(dx>=dy)
	{
		length=dx;
	}
	else
	{
	length=dy;
	}
dx=(x2-x1)/length;
dy=(y2-y1)/length;


x=x1+0.5*(dx);
y=y1+0.5*(dy);
i=1;
while(i<=length)
{

cout<<"\n"<<x<<"\t"<<y;
putpixel(x,y,5);
x=x+dx;
y=y+dy;

i++;
}


}
