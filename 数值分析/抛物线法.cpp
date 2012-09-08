
//18-12-06 11:43
//抛物线法 
//抛物线法是牛顿法和弦截法的进化,效率更高 
#include<iostream>
#include<iomanip>
#include<math.h>
#include<conio.h>
using namespace std;

double x,x1,x2;
double a;//精度要求 


inline double fun( double x)//函数f(x) 
{
       return pow(x,3) - 3*x - 1; //f(x)=x^3-3*x-1
}

inline double fun1(double x1,double x) //一阶差分 
{
       return (fun(x)-fun(x1))/(x-x1);
}

double inline fun2(double x2,double x1,double x)//二阶差分 
{
       return (fun1(x2,x)-fun1(x2,x1))/(x-x1);
}

void Muller()
{
     int k=0;
     cout<<k++<<"\t"<<x2<<endl;
     cout<<k++<<"\t"<<x1<<endl;
     cout<<k++<<"\t"<<x<<endl;
     double w,m;
     while(k<10)
     {
           w=fun1(x,x1)+fun2(x,x1,x2)*(x-x1);
           m=sqrt(w*w-4*fun(x)*fun2(x2,x1,x));
           x2=x1;
           x1=x;
           if(w>0)
           {
                  x=x-2*fun(x)/(w+m);
           }
           else
               x=x-2*fun(x)/(w-m);
           cout<<k++<<"\t"<<fixed<<setprecision(10)<<x<<endl;
     }
}

int main()
{
    x=2;
    x1=3;
    x2=1;
    cout<<"the result of that f(x)=x^3-3*x-1 when x0=1,x1=3,x3=2 is:\n";
    Muller();
    cout<<"\npress any key to continue;";
    getch();
    
}
