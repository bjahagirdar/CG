#include<iostream>
#include<graphics.h>
#include<math.h>
using namespace std;
	
void DDA(float x1,float y1,float x2,float y2)   //DDA
{
	float dx,dy,steps,xinc,yinc,x,y;
	dx=x2-x1;
	dy=y2-y1;
	if(abs(dx)>=abs(dy))
	steps=dx;
	else
	steps=dy;
   
	xinc=dx/steps;
	yinc=dy/steps;
   
	x=x1;
	y=y1;
   
	putpixel(x1,y1,5);
   
	for(int i=1;i<=steps;i++)
	{
	    x+=xinc;
	    y+=yinc;
	    putpixel(round(x),round(y),5);
	 }
   
}
void dot(float x1,float y1,float x2,float y2)
{	
	float dx,dy,xinc,yinc,steps,x,y;
	dx=x2-x1;
	dy=y2-y1;
	
	if(abs(dx)>=abs(dy))
		steps=dx;
	else
		steps=dy;
		
	xinc=dx/steps;
	yinc=dy/steps;
	
	int gd=DETECT,gm;
	initgraph(&gd,&gm,NULL);
	
	x=x1;
	y=y1;
	
	putpixel(x1,y1,3);
	
	for(int i=1;i<=steps;i++)
	{
		x=x+xinc;
		y=y+yinc;
		
		if(i%2==0)
			putpixel(x,y,3);
		delay(20);
	}
	delay(5000);
	closegraph();
	

}

void dash(float x1,float y1,float x2,float y2)
{
	float dx,dy,xinc,yinc,steps,x,y;
	dx=x2-x1;
	dy=y2-y1;
	
	if(abs(dx)>=abs(dy))
		steps=dx;
	else
		steps=dy;
		
	xinc=dx/steps;
	yinc=dy/steps;
	
	int gd=DETECT,gm;
	initgraph(&gd,&gm,NULL);
	
	x=x1;
	y=y1;
	
	putpixel(x1,y1,3);
	
	for(int i=1;i<=steps;i++)
	{
		x=x+xinc;
		y=y+yinc;
		
		if(i%15!=0 )
			putpixel(x,y,3);
		delay(20);
	}
	delay(5000);
	closegraph();	
}

void dash_dot(float x1,float y1,float x2,float y2)
{
	float dx,dy,steps,xinc,yinc,x,y;
	dx=x2-x1;
	dy=y2-y1;
	if(abs(dx)>=abs(dy))
	steps=dx;
	else
	steps=dy;
   
	xinc=dx/steps;
	yinc=dy/steps;
   
	x=x1;
	y=y1;
    
    int gd=DETECT,gm;
	initgraph(&gd,&gm,NULL);
	
	putpixel(x1,y1,3);
   
	for(int i=1;i<=steps;i++)
	{
	    x+=xinc;
	    y+=yinc;
	    if(i%10!=5 && i%10!=7)
	    putpixel(round(x),round(y),5);
	    delay(50);
	 }
	 delay(5000);
	closegraph();	
}

void thick(float x1,float y1,float x2,float y2,int w)
{
	float dx,dy,wx,wy;
	dx=x2-x1;
	dy=y2-y1;
	
	int gd=DETECT,gm;
	initgraph(&gd,&gm,NULL);
	
	if(dx>=dy)
	{
		wy=((w-1)*sqrt(((y2-y1)*(y2-y1))+((x2-x1)*(x2-x1))))/(2*(abs(x2)-abs(x1)));
		
		for(int i=0;i<wy;i++)
		{
			DDA(x1,y1+i,x2,y2+i);
			DDA(x1,y1-i,x2,y2-i);
		}
	
	}
	else
	{
		wx=((w-1)*sqrt(((y2-y1)*(y2-y1))+((x2-x1)*(x2-x1))))/(2*(abs(y2)-abs(y1)));
		
		for(int i=0;i<wx;i++)
		{
			DDA(x1+i,y1,x2+i,y2);
			DDA(x1-i,y1,x2-i,y2);
		}
	
	}
	delay(5000);
	closegraph();
	

}




int main()
{

float x_1,x_2,y_1,y_2;
int c,w;

do
{
		cout<<"MENU\n\n1 : Dotted Line.\n2 : Dashed Line.\n3 : Dotted Dashed Line.\n4 : Thick Line.\n5 : Exit";
	cout<<"\nEnter your choice :";
	cin>>c;
	
	cout<<"\n";
	
	switch(c)
	{
		
		case 1 :cout<<"\nEnter first vertex (x1,y1) : ";
				cin>>x_1>>y_1;
				cout<<"\nEnter second vertex (x2,y2) :";
				cin>>x_2>>y_2;
				dot(x_1,y_1,x_2,y_2);
				break;
			
		case 2 :cout<<"\nEnter first vertex (x1,y1) : ";
				cin>>x_1>>y_1;
				cout<<"\nEnter second vertex (x2,y2) :";
				cin>>x_2>>y_2;
				dash(x_1,y_1,x_2,y_2);
				break;
				
		case 3 :cout<<"\nEnter first vertex (x1,y1) : ";
				cin>>x_1>>y_1;
				cout<<"\nEnter second vertex (x2,y2) :";
				cin>>x_2>>y_2;
				dash_dot(x_1,y_1,x_2,y_2);
				break;
				
		case 4 :cout<<"\nEnter first vertex (x1,y1) : ";
				cin>>x_1>>y_1;
				cout<<"\nEnter second vertex (x2,y2) :";
				cin>>x_2>>y_2;
				cout<<"\nEnter thickness : ";
				cin>>w;
				thick(x_1,y_1,x_2,y_2,w);
				break;
						
		case 5 :cout<<"\nExitted!!!";
				break;
		
		default:cout<<"\nEnter a valid choice.\n";
	}
	
}while(c!=5);

return 0;
}
