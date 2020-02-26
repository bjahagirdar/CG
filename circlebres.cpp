#include<iostream>
#include<graphics.h>
using namespace std;

class bres_circle
{
    float xc,yc,r;
public:
    void accept()
    {
        cout<<"\n Enter the centre point (x,y) of the circle : ";
        cin>>xc>>yc;
        cout<<"\nEnter radius of circle : ";
        cin>>r;
        bcircle();   
    }
   
    void bcircle()
    {
        float d,x,y;
        int gd=DETECT,gm;
        initgraph(&gd,&gm,NULL);
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
            delay(60);
        }
        delay(10000);
        closegraph();
           
    }
};

int main()
{
    bres_circle s;
    s.accept();
    return 0;
 }
