#include<graphics.h>
//#include<conio.h>
#include<math.h>

void koch(int x1, int y1, int x2, int y2, int it)
{
 float angle = 60*3.14/180;
 int x3 = (2*x1+x2)/3;
 int y3 = (2*y1+y2)/3;

 int x4 = (x1+2*x2)/3;
 int y4 = (y1+2*y2)/3;
	
 int x = x3 + (x4-x3)*cos(angle)+(y4-y3)*sin(angle);
 int y = y3 - (x4-x3)*sin(angle)+(y4-y3)*cos(angle);

 if(it > 0)
 {
  koch(x1, y1, x3, y3, it-1);
  koch(x3, y3, x, y, it-1);
  koch(x, y, x4, y4, it-1);
  koch(x4, y4, x2, y2, it-1);
 }
 else
 {
	setcolor(5);
  line(x1, y1, x3, y3);
  line(x3, y3, x, y);
  line(x, y, x4, y4);
  line(x4, y4, x2, y2);
delay(2);
 }
}

int main(void)
{
 int gd = DETECT, gm;
 initgraph(&gd, &gm, NULL);
 int x1 = 100, y1 = 300, x2 = 500, y2 = 300;
 koch(x1, y1, x2, y2, 4);
 delay(1000);
 closegraph();
 
 getch();
 return 0;
}
