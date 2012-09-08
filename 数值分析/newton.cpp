
/*
  Name: newton 迭代法 
  Copyright: 
  Author: TrueCN
  Date: 15-12-06 23:33
  Description: 
*/

//迭代方程为X(k+1) = X(k) - f(x)/f'(x) ;

#include<iostream>
#include<math.h>
#include<iomanip>
using namespace std;

double x=2;//初始值 
double a;//精度要求 

inline double fun( double x)//函数f(x) 
{
       return pow(x,3) - 3*x - 1;
}

inline double fun1(double x)//f(x)的导数 
{
       return 3*x*x - 3;
}

void Newton()
{
     int k=0;
     cout<<k++<<"\t"<<x<<endl;
     while(k<20)
     {
            a=x;
            x = x-fun(x)/fun1(x);
            cout<<k++<<"\t"<<fixed<<setprecision(10)<<x<<endl;
            //if(abs(a-x)<0.0001)break;//精度为0.0001时退出 
     }
}

int main()
{

    Newton();
    
    system("pause");
    return 0;
}
