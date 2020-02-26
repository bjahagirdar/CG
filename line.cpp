#include<graphics.h>
#include<iostream>
using namespace std;
class pixel
{

public :
    void plot(int x1,int y1,int c)
    {
        putpixel(x1,y1,c);
    }
};

class combine: public pixel
{
    float x,y,x1,y1,x2,y2,dx,dy,steps,xinc,yinc;
    int a1,b1,a2,b2;
public:
    void accept();
    void drawline(float,float,float,float);            //DDA
    void drawline(int,int,int,int);                 //Bresenham
};

void combine::accept()
{
    int ch;
    cout<<"\n                      MENU";
    do
    {
        cout<<"\n1 : DDA";   
        cout<<"\n2 : Bresenham";
        cout<<"\n3 : EXIT";
        cout<<"\nEnter your choice : ";
        cin>>ch;
        switch(ch)
        {
            case 1 : cout<<"\nEnter first point (x1,y1) : ";
                     cin>>x1>>y1;
                     cout<<"\nEnter second point (x1,y1) : ";
                     cin>>x2>>y2;
                     drawline(x1,y1,x2,y2);
                     break;
       
            case 2 : cout<<"\nEnter first point (x1,y1) : ";
                     cin>>a1>>b1;
                     cout<<"\nEnter second point (x1,y1) : ";
                     cin>>a2>>b2;
                     drawline(a1,b1,a2,b2);
                     break;
       
            case 3 : cout<<"\nExitted...!\n";
                     break;
                     
            default : cout<<"\nEnter a valid option..\n";
        }
   
   
    }while(ch!=3);
}

void combine::drawline(float x1,float y1,float x2,float y2)   //DDA
{
    int gd=DETECT,gm;              //graphics driver and mode
    initgraph(&gd,&gm,NULL);
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
   
    plot(x1,y1,3);
   
    for(int i=1;i<=steps;i++)
    {
        x+=xinc;
        y+=yinc;
        plot(round(x),round(y),3);
        delay(50);
    }
    delay(10000);
    closegraph();
}

void combine::drawline(int x1,int y1,int x2,int y2)   //Bresenham
{
    int gd=DETECT,gm;              //graphics driver and mode
    initgraph(&gd,&gm,NULL);
    dx=x2-x1;
    dy=y2-y1;
    int x,y;
   
    if(dx<dy)

    {
        cout<<"\n Slope of line is steep.";
        return;
    }
       
    x=x1;
    y=y1;
    putpixel(x,y,3);
    int pk = (2*dy)-dx;
    for(int i=0;i<dx;i++)
    {     
        if(pk<0)
        {
            x++;
            pk= pk+(2*dy);
        }
        else
        {
               x++;
               y++;
              pk = pk+(2*dy)-2*dx;
        }
        plot(x,y,3);
        delay(30);
    }


    delay(10000);
    closegraph();




}

int main()
{
    combine c;
    c.accept();


   
    return 0;
}
