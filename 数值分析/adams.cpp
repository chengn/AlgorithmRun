
/*
  Name: adams 
  Copyright: chengning
  Author: chengning
  Date: 29-12-06 23:09
  Description: 
               四阶R_K法的基本公式为 :
  y(n+1)=y(n)+h*(K1+2*K2+2*K3+K4)/6;
  K1 = f(x(n),y(n));
  K2 = f(x(n)+h/2,y(n)+h*K1/2);
  K3 = f(x(n)+h/2,y(n)+h*K2/2);
  K4 = f(x(n)+h,y(n)+h*K3);
四阶adams法具体为:
   显式:  y(n4) = y(n3)+h*(55*f(x(n3),y(n3))-59*f(x(n2),y(n2))+37*f(x(n1),y(n1))-9*f(x(n),y(n)))/24;
   隐式:  y(n4) = y(n3)+h*(9*f(x(n4),y(n4))+19*f(x(n3),y(n3))-5*f(x(n2),y(n2))+f(x(n1),y(n1)))/24;
*/

//本cpp中的例子来于数值分析(李庆扬,TUP)p364例6
//r-p法启动adams 

#include<iostream>
#include<iomanip>
#include<conio.h>
using namespace std;

const float h(0.1);//步长 
double x(0),y(1);//初值 

inline double fun(double x,double y)//初始导函数 
{
       return -y+x+1;
}
double R_K(double x,double y)//启动 
{
       double k1,k2,k3,k4;
       k1=fun(x,y);
       k2=fun(x+h/2,y+h*k1/2);
       k3=fun(x+h/2,y+h*k2/2);
       k4=fun(x+h,y+h*k3);
       return y+h*(k1+2*k2+2*k3+k4)/6;
}

void adams()
{
     double yn1,yn2,yn3,yn4,xn1,xn2,xn3,xn4;
     xn1=x+h;
     yn1=R_K(x,y);
     xn2=xn1+h;
     yn2=R_K(xn1,yn1);
     xn3=xn2+h;
     yn3=R_K(xn2,yn2);//预估yn3
     yn3=yn2+h*(9*fun(xn3,yn3)+19*fun(xn2,yn2)-5*fun(xn1,yn1)+fun(x,y))/24;//校正
     cout<<xn3<<"\t\t"<<yn3<<endl;
     while(xn4<1)
     {
                 xn4=xn3+h;
                 //显式预估
                 yn4=yn3+h*(55*fun(xn3,yn3)-59*fun(xn2,yn2)+37*fun(xn1,yn1)-9*fun(x,y))/24;
                 cout<<xn4<<"\t"<<yn4;
                 //隐式校正
                 yn4=yn3+h*(9*fun(xn4,yn4)+19*fun(xn3,yn3)-5*fun(xn2,yn2)+fun(xn1,yn1))/24;
                 cout<<"\t  "<<yn4<<endl;
                 x=xn1;
                 y=yn1;
                 xn1=xn2;
                 yn1=yn2;
                 xn2=xn3;
                 yn2=yn3;
                 xn3=xn4;
                 yn3=yn4;
     } 
}
int main()
{
    cout<<"x\tadama显式  隐式\n";
    adams();
    cout<<"press any key to continue!";
    getch();
    return 0;
}
