
/*
  Name: newton ������ 
  Copyright: 
  Author: TrueCN
  Date: 15-12-06 23:33
  Description: 
*/

//��������ΪX(k+1) = X(k) - f(x)/f'(x) ;

#include<iostream>
#include<math.h>
#include<iomanip>
using namespace std;

double x=2;//��ʼֵ 
double a;//����Ҫ�� 

inline double fun( double x)//����f(x) 
{
       return pow(x,3) - 3*x - 1;
}

inline double fun1(double x)//f(x)�ĵ��� 
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
            //if(abs(a-x)<0.0001)break;//����Ϊ0.0001ʱ�˳� 
     }
}

int main()
{

    Newton();
    
    system("pause");
    return 0;
}
