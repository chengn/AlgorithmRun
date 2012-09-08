#include<iostream>
#include<iomanip>
#include<math.h>
using  namespace std;

const double a=1;
const double b=2;
const double A=0.05;

inline double fun(double x)//f(x)函数 
{
       return pow(x,2)-x-1;
} 

void Binary()
{
    double low=a,mid,high=b;
    if(fun(a)*fun(b)>0)cout<<"error!\n";
    if(a>b)cout<<"error!\n";
    int k=0;
    cout<<"k"<<"\t"<<"low"<<"\t"<<"high"<<"\t"<<"mid"<<endl<<endl;
    while(k<20)//迭代次数限制 
    {
         //if((high-low)<A)break;精度要求 
         
         mid = (high+low)/2;
         cout<<k++<<"\t";
         cout<<fixed<<setprecision(10)<<low<<"\t"<<high<<"\t";
         cout.precision(10);
         cout<< mid <<endl;
         if(fun(mid)==0)break;
         else if(fun(mid)>0)
             high = mid;
         else
            low = mid;
    }
}

int main()
{
    Binary();
    
    system("pause");
    
    return 0;
}
