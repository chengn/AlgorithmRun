//梯形法
//改进欧拉法 
//常微分方程初值问题数值解法 

#include<iostream>
#include<math.h>
#include<iomanip>
#include<conio.h>
using namespace std;

const double A=0.5;
const float h=0.1;
const float B=0;//初始值 
double x,y;
double Y,x1,yi;

inline double funD(double x,double y)//y'=x^2+x-y
{
       return x*x + x - y;
} 

inline double fun(double x)//y=-e^(-x) + x^2-x+1
{
       return -exp(-x)+x*x-x+1;
}

void tixing()
{
     x=0.0;
     y=B;
     yi=y+h*funD(x,y);
     while(x<A)
     {
          x1=x+h;
          yi=y+(h/2)*(funD(x,y)+funD(x1,yi));
          Y=fun(x1);
          cout<<x1<<"\t"<<yi<<"\t"<<Y<<endl;
          x=x1;
          y=yi;
     }
}
void advanceeula()
{
     x=0.0;
     y=B;
     double yp,yc;
     while(x<A)
     {
               x1=x+h;
               yp=y+h*funD(x,y);
               yc=y+h*funD(x1,yp);
               yi=(yp+yc)/2;
               Y=fun(x1);
               cout<<x1<<"\t"<<yi<<"\t"<<Y<<endl;
               x=x1;
               y=yi;
     }
}

int main()
{
    cout<<fixed<<setprecision(7);
    cout<<"梯形法结果:\n";
    tixing();
    cout<<"改进欧拉法结果:\n";
    advanceeula();
    
    cout<<"\npress any key to  continue.\n";
    getch();
    
    return 0;
}
