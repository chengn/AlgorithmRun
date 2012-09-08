
/*
  Name: 迭代求线形方程 
  Copyright: 
  Author: TrueCN
  Date: 08-12-06 22:02
  Description: //可作为模板,只需改变fun函数及N,A等 
*/


#include<iostream>
#include<iomanip>
#include<math.h>
using namespace std;

const double N=1.5;//X0   初值 
const double A=0.00001;    //精度要求 

inline double fun(double x)
{
       return pow((1+x*x),(double)1/3);   //Φ(x)=(1+x^2)^1/3
}

void Iterative()
{
    double m = N;
    int k=0;
    while(k<20)//用精度要求stop  while()或者迭代次数 
    {
              cout<<k<<"\t"<<fixed<< setprecision(10)<<m<<endl;
              m = fun(m);
              k++;
    }
}

int main()
{
    Iterative();
    
    system("pause");
    
    return 0;
}
