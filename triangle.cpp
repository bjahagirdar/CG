#include<graphics.h>
#include<iostream>
using namespace std;

class triangl
{	
	float xc,yc,r,x1,y1,x2,y2,x3,y3;

public:

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
	   
		putpixel(x1,y1,3);
	   
		for(int i=1;i<=steps;i++)
		{
		    x+=xinc;
		    y+=yinc;
		    putpixel(round(x),round(y),3);
		    delay(5);
		}
	   
	}
	
	void bcircle(float xc,float yc, float r)
    {
        float d,x,y;
        x=0;
        y=r;
        putpixel(x+xc,y+yc,1);
        d=3-2*r;
        while(x<=y)
        {
            if(d<0)
            {
                d+=4*x+6;
            }   
            else
            {
                d+=4*x-4*y+10;
                y--;
            }       
            x++;
            putpixel(xc+x , yc+y , 3);   
            putpixel(xc+y , yc+x , 3);
            putpixel(xc-x , yc+y , 3);
            putpixel(xc+y , yc-x , 3);
            putpixel(xc+x , yc-y , 3);
            putpixel(xc-y , yc+x , 3);
            putpixel(xc-x , yc-y , 3);
            putpixel(xc-y , yc-x , 3);   
            delay(5);
        }  
    }

	
	void accept()
	{
		cout<<"\nEnter centre of circum-circle : ";
		cin>>xc>>yc;
	
		cout<<"\nEnter radius of circum-circle : ";
		cin>>r;
		
	}
	
	void circle1()
	{
		bcircle(xc,yc,r);
		bcircle(xc,yc,(r/2));
	}
	
	
	void triangle()
	{
		x1=xc;
		y1=yc-r;
		x2=xc-((1.73205080757*r)/2);
		y2=yc+(r/2);
		x3=xc+((1.73205080757*r)/2);
		y3=yc+(r/2);
		DDA(x1,y1,x2,y2);
		DDA(x2,y2,x3,y3);
		DDA(x1,y1,x3,y3);
	}
	
};
int main()
{
	triangl a;
	a.accept();
	
    int gd=DETECT,gm;              //graphics driver and mode
    initgraph(&gd,&gm,NULL);
	
	a.circle1();
	a.triangle();
	
    delay(10000);
     closegraph();
    return 0;
    
 }
 
 
