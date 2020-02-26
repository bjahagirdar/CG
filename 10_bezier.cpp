#include<iostream>
#include<graphics.h>
using namespace std;
int main()
{
int gd=DETECT,gm;

int x[4],y[4],px,py,i;
cout<<"Enter four control points of bezier curve: ";
for(i=0;i<4;i++)
{
cin>>x[i]>>y[i];
}
initgraph(&gd,&gm,NULL);
double t;
for(t=0.0;t<=1.0;t+=0.001){
px=pow(1-t,3)*x[0]+3*t*pow(1-t,2)*x[1]+3*pow(t,2)*(1-t)*x[2]+pow(t,3)*x[3];
py=pow(1-t,3)*y[0]+3*t*pow(1-t,2)*y[1]+3*pow(t,2)*(1-t)*y[2]+pow(t,3)*y[3];

putpixel(px,py,WHITE);
delay(2);
}
delay(1000);
closegraph();
}



