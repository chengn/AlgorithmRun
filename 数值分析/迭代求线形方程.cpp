
/*
  Name: ���������η��� 
  Copyright: 
  Author: TrueCN
  Date: 08-12-06 22:02
  Description: //����Ϊģ��,ֻ��ı�fun������N,A�� 
*/


#include<iostream>
#include<iomanip>
#include<math.h>
using namespace std;

const double N=1.5;//X0   ��ֵ 
const double A=0.00001;    //����Ҫ�� 

inline double fun(double x)
{
       return pow((1+x*x),(double)1/3);   //��(x)=(1+x^2)^1/3
}

void Iterative()
{
    double m = N;
    int k=0;
    while(k<20)//�þ���Ҫ��stop  while()���ߵ������� 
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
