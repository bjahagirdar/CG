#include<iostream>
#include<graphics.h>
#include<math.h>
using namespace std;
class pixel
{
public:
void put_pixel(int x,int y,int z)
{
putpixel(x,y,5);
}
};
class Circle
{
public:
void cir(int xc,int yc,int r)
{
int d=3-(2*r);
int x=0;
int y=r;
putpixel(xc+x,yc+y,5);
while(x<=y)
{
if(d<0)
{
x=x+1;
y=y;
d=d+(4*x)+6;
}
else
{
x=x+1;
y=y-1;
d=d+(4*(x-y))+10;
}
putpixel(xc+x,yc+y,5);
putpixel(xc+y,yc+x,5);
putpixel(xc+x,yc-y,5);
putpixel(xc-y,yc+x,5);
putpixel(xc-x,yc-y,5);
putpixel(xc-y,yc-x,5);
putpixel(xc-x,yc+y,5);
putpixel(xc+y,yc-x,5);
}
}
void dda(int x1,int y1,int x2,int y2)
{
int length;
int i=1;double dx,dy,x,y;
dx=x2-x1;
dy=y2-y1;
if(dx>=dy)
length=dx;
else
length=dy;
dx=dx/length;
dy=dy/length;
if(dx>=0)
x=x1+0.5*1;
else
x=x1+0.5*(-1);
if(dy>=0)
y=y1+0.5*1;
else
y=y1+0.5*(-1);
while(i<=length)
{
putpixel(x,y,WHITE);
x=x+dx;
y=y+dy;
i++;
}
}
};
int main()
{
Circle obj;
int gd=DETECT,gm;
initgraph(&gd,&gm,NULL);
for(int i=0;i<600;i++)
{
//Head
obj.cir(20+i,250,20);
obj.dda(20+i,270,20+i,340);
//Eye
obj.cir(27+i,248,1);
//leg
obj.dda(20+i,340,5+i,380);
obj.dda(20+i,340,35+i,380);
//handobj.dda(20+i,290,40+i,300);
obj.dda(40+i,300,60+i,270);
//1st Balloon
line(60+i,270,60+i,180);
obj.cir(60+i,160,20);
//2nd Balloon
obj.dda(60+i,270,100+i,180);
obj.cir(110+i,160,20);
//3rd Balloon
obj.dda(60+i,270,150+i,180);
obj.cir(160+i,160,20);
//Road
obj.dda(0,380,700,380);
delay(40);
cleardevice();
}
closegraph();
}
