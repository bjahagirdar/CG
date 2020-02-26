/* write c++ prog to draw 2d obj and perform foll transformation:
1 translation
2 scaling
3 rotation*/
#include <iostream>
#include <graphics.h>
#include <math.h>
using namespace std;
void translation()
{
	int x1,y1,x2,y2,x3,y3,tx,ty,tz;
	cout<<"ENTER CO-ORDINATES"<<endl;
	cin>>x1>>y1>>x2>>y2>>x3>>y3;
	cout<<"ENTER TRANSLATION FACTOR IN TERMS OF X AND Y"<<endl;
	cin>>tx>>ty;
	int gd=DETECT,gm;
	initgraph(&gd,&gm,NULL);
	line(x1,y1,x2,y2);
	line(x1,y1,x3,y3);
	line(x2,y2,x3,y3);
	x1+=tx;
	y1+=ty;
	x2+=tx;
	y2+=ty;
	x3+=tx;
	y3+=ty;
	line(x1,y1,x2,y2);
	line(x1,y1,x3,y3);
	line(x2,y2,x3,y3);
	delay(2000);
	 closegraph();
}

void scaling()
{

	int x1,y1,x2,y2,x3,y3,tx,ty;
	cout<<"ENTER CO-ORDINATES"<<endl;
	cin>>x1>>y1>>x2>>y2>>x3>>y3;
	cout<<"ENTER SCALING FACTOR IN TERMS OF X AND Y"<<endl;
	cin>>tx>>ty;
	int gd=DETECT,gm;
	initgraph(&gd,&gm,NULL);
	line(x1,y1,x2,y2);
	line(x1,y1,x3,y3);
	line(x2,y2,x3,y3);
	x1=x1*tx;
	y1=y1*ty;
	x2=x2*tx;
	y2=y2*ty;
	x3=x3*tx;
	y3=y3*ty;
	line(x1,y1,x2,y2);
	line(x1,y1,x3,y3);
	line(x2,y2,x3,y3);
	delay(2000);
	 closegraph();
}
void rotation()
{

	int x1,y1,x2,y2,x3,y3;
	float ang;
	cout<<"ENTER CO-ORDINATES OF TRAINGLE"<<endl;
	cin>>x1>>y1>>x2>>y2>>x3>>y3;
	cout<<"ENTER ANGLE OF ROTATION"<<endl;
	cin>>ang;
	ang=ang*3.14;
	ang=ang/180;
	int gd=DETECT,gm;
	initgraph(&gd,&gm,NULL);
	line(x1,y1,x2,y2);
	line(x2,y2,x3,y3);
	line(x1,y1,x3,y3);
	x2=x2*cos(ang)-y2*sin(ang);
	y2=x2*sin(ang)+y2*cos(ang);
	x3=x3*cos(ang)-y3*sin(ang);
	y3=x3*sin(ang)+y3*cos(ang);
	line(x1,y1,x2,y2);
	line(x2,y2,x3,y3);
	line(x1,y1,x3,y3);
	delay(2000);
	closegraph();

}

int main()
{
	int ch;
	do{
	
	cout<<"1 TRANSLATION"<<endl<<"2 SCALING"<<endl<<"3 ROTATION"<<endl<<"0 EXIT"<<endl;
	cin>>ch;
	switch(ch)
	{
	case 1:
	translation();
	break;
	
	case 2:
	scaling();
	break;
	
	case 3:
	rotation();
	break;
	}
	}while(ch!=0);	
}
	

