#include<iostream>
#include<graphics.h>
#include<unistd.h>
using namespace std;
void boundary(int,int,int,int);
void flood_fill(int,int,int,int);
class pixel1
{

protected:
	int x,y,c;
public:
	void put_pixel(int x,int y,int c)
	{
		putpixel(x,y,c);
	}
};

 
class Line:public pixel1
 {
  float x,y,dx,dy,steps,xm,ym,xin,yin;
  public:
   void drawline(float x1,float y1,float x2,float y2)
    {
     x=x1;
     y=y1;
     put_pixel(x,y,3);
     dx=x2-x1;
    dy=y2-y1;
    if(abs(dx)>=abs(dy))
    steps=dx;
    else
    steps=dy;
  xin=(float)(dx/steps);
  yin=(float)(dy/steps);
  for(int i=1;i<=steps;i++)
 	  {
    x=x+xin;
    y=y+yin;
    xm=x+0.5;
    ym=y+0.5;
    put_pixel(xm,ym,3);
   	}
    }
  };
  
 void boundary(int x,int y,int fc, int bc)
 {
   if((getpixel(x,y)!=bc) && (getpixel(x,y)!=fc))
   	{
   		putpixel(x,y,fc);
   		delay(1);
   		boundary((x)+1,y,fc,bc);
   		boundary(x,(y)+1,fc,bc);
   		boundary((x)-1,y,fc,bc);
   		boundary(x,(y)-1,fc,bc);
   	}
  } 
  
void flood_fill(int x,int y,int old,int f)
{
int current = getpixel(x,y);
	if(current == old) 
	{
		putpixel(x,y,f);
		delay(1);
            flood_fill(x-1,y,old,f);
		flood_fill(x+1,y,old,f);
		
		flood_fill(x,y+1,old,f);
		flood_fill(x,y-1,old,f);
	}
}
int main()
 {
  Line z;
  int gd=DETECT,gm,n;
  initgraph(&gd,&gm,NULL);
  
          cout<<"\n\n\n\n\nFLOODFILL"; 
        
         int choice;
         char c;  
           
        do
	{
	cout<<"\n(1)boundary\n(2)floodfill\n(3)exit\n";
	cout<<"The type of polygon you want to draw ? :\n";
	cin>>choice;
	switch(choice)
	{
		case 1:
		int x1,y1,w,h,xm,ym;
  	cout<<"Enter x1,y1,w,h:"<<endl;
  	cout<<"\nx1 = ";
  	cin>>x1;
 	 cout<<"y1 = ";
  	   cin>>y1;
  	   cout<<"width = ";
  	   cin>>w;
  	   cout<<"height = ";
  	   cin>>h;
           z.drawline(x1,y1,x1,y1+h);
           z.drawline(x1,y1+h,x1+w,y1+h);
           z.drawline(x1+w,y1,x1+w,y1+h);
           z.drawline(x1,y1,x1+w,y1);
           xm=x1+10;
           ym=y1+10;
           boundary(xm,ym,5,3);
		break;
		
     case 2:
		
		int x,y,w1,h1,xm1,ym1;
  	cout<<"Enter x1,y1,w,h:"<<endl;
  	cout<<"\nx1 = ";
  	cin>>x1;
 	 cout<<"y1 = ";
  	   cin>>y1;
  	   cout<<"w = ";
  	   cin>>w1;
  	   cout<<"h = ";
  	   cin>>h1;
           z.drawline(x1,y1,x1,y1+h1);
           z.drawline(x1,y1+h1,x1+w1,y1+h1);
           z.drawline(x1+w1,y1,x1+w1,y1+h1);
           z.drawline(x1,y1,x1+w1,y1);
           xm1=x1+10;
           ym1=y1+10;
           flood_fill(xm1,ym1,BLACK,WHITE);   
		
		break;
		
		case 3:cout<<"Incorrect :";
		break;
	}
	
	cout<<"\nDo you want to continue : (y/n) ";
	cin>>c;
	}while(c=='y');
      

  getchar();
  closegraph();
      return 0;

 }
