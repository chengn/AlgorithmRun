
/*
  Name: 十进制转换成8进制 
  Copyright: 
  Author: TrueCN
  Date: 03-11-06 23:48
  Description: 
*/


#include<iostream>
using namespace std;

int const N=10;//最大为十位数 
int const H=8;//转换成八进制 


int fun(int n)
{
    int M[N],i=0;
    M[i++]=n%H;
    if(n/H>0)
       fun(n/H);
    
    for(int j=i-1;j>=0;j--)
       cout<<M[j];
}

int main()
{
    int num;
    cin>>num;
    fun(num);
    system("pause");
    return 0;
}
