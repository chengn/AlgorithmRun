
/*
  Name: 弦截法(拟牛顿法)
  Copyright: 
  Author: TrueCN
  Date: 16-12-06 00:07
  Description: 
*/
//迭代方程为X(k+1) = X(k) - f(x)/d(x) ;  d(x)=(f(x)-f(x1))/(x-x1);
//弦截法(拟牛顿法)主要是将牛顿法中的f'(x)换成d(x) 

#include<iostream>
#include<math.h>
#include<iomanip>
using namespace std;

double x=1.9,x1=2;//初始值 ,x=x(k),x1=x(k-1)
double a;//精度要求 

inline double fun( double x)//函数f(x) 
{
       return pow(x,3) - 3*x - 1; //f(x)=x^3-3*x-1
}

inline double fun1(double x,double x1) 
{
       return (fun(x)-fun(x1))/(x-x1);
}

void xianjie()//弦截法(拟牛顿法) 
{
     int k=0;
     cout<<k++<<"\t"<<x1<<endl;
     cout<<k++<<"\t"<<x<<endl;
     while(1)
     {
            a=x;
            x = x-fun(x)/fun1(x,x1);
            cout<<k++<<"\t"<<fixed<<setprecision(10)<<x<<endl;
            if(fabs(a-x)<0.00001)break;//精度为0.00001时退出 
            x1 = a;
            
     }
}

int main()
{

    xianjie();
    
    system("pause");
    return 0;
}
