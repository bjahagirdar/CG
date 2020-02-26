#include<graphics.h>
#include<iostream>
using namespace std;

class rectangl
{    float x1,y1,x2,y2,x3,y3,x4,y4,mx1,my1,mx2,my2,mx3,my3,mx4,my4,mmx1,mmy1,mmx2,mmy2,mmx3,mmy3,mmx4,mmy4;

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
   
    void accept()
    {
        cout<<"\nEnter top-left point of the rectangle : ";
        cin>>x1>>y1;
   
        cout<<"\nEnter bottom-right point of the rectangle : ";
        cin>>x3>>y3;
       
    }
   
    void rectangle1()
    {
        x2=x3;
        y2=y1;
        x4=x1;
        y4=y3;
       
        DDA(x1,y1,x2,y2);
        DDA(x2,y2,x3,y3);
        DDA(x4,y4,x3,y3);
        DDA(x1,y1,x4,y4);
    }
   
   
    void diamond1()
    {
        mx1=(x1+x2)/2;
        my1=(y1+y2)/2;
        mx2=(x2+x3)/2;
        my2=(y2+y3)/2;
        mx3=(x3+x4)/2;
        my3=(y3+y4)/2;
        mx4=(x1+x4)/2;
        my4=(y1+y4)/2;
   
        DDA(mx1,my1,mx2,my2);
        DDA(mx3,my3,mx2,my2);
        DDA(mx4,my4,mx3,my3);
        DDA(mx4,my4,mx1,my1);
   
    }
   
    void rectangle2()
    {
        mmx1=(mx1+mx2)/2;
        mmy1=(my1+my2)/2;
        mmx2=(mx2+mx3)/2;
        mmy2=(my2+my3)/2;
        mmx3=(mx3+mx4)/2;
        mmy3=(my3+my4)/2;
        mmx4=(mx1+mx4)/2;
        mmy4=(my1+my4)/2;
   
        DDA(mmx1,mmy1,mmx2,mmy2);
        DDA(mmx3,mmy3,mmx2,mmy2);
        DDA(mmx4,mmy4,mmx3,mmy3);
        DDA(mmx4,mmy4,mmx1,mmy1);
   
    }

};
int main()
{
    rectangl a;
    a.accept();
   
    int gd=DETECT,gm;              //graphics driver and mode
    initgraph(&gd,&gm,NULL);
    a.rectangle1();
    a.diamond1();
    a.rectangle2();
    delay(10000);
    closegraph();
    return 0;
   
 }
