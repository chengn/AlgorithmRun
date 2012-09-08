

/*
  Name: 解线形方程组的基本迭代法 
  Copyright: 
  Author: TrueCN
  Date: 15-12-06 17:45
  Description: 
*/
 
#include<iostream>
#include<iomanip>
using namespace std;

int n; //线性方程的维数
double *M;//辅助距阵
double *N;//辅助距阵
int **a;//线形方程的系数距阵
int *b;//常数项距阵
double *x;//解距阵

void initializtion()   //初始化线形方程
{
 cout<<"输入线性方程的维数:  ";
    cin>>n;
 M=new double[n];
 N = new double[n];
 a = new int*[n];
 for(int i=0;i<n;i++)
        a[i] = new int[n];
 b = new int[n];
 x = new double[n]; 
 cout<<"输入线形方程的系数距阵:\n";
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
             cin >> a[i][j];
 cout<<"输入线形方程组的常数项距阵:\n";
 for(int k=0;k<n;k++)
 {
  cin>>b[k];
  x[k] = 0.0;//初始化x 
 }

}



void Gaussseidel()//高斯--塞得尔迭带法 
{
     cout<<"Gauss-seidel:\n";
 int t=0;//迭代次数
 while(t<20)//次数限制,精度要求,此处可修改,是迭带开关 
 {
  for(int i=0;i<n;i++)
  {
   M[i] = 0;       
   for(int j=0;j<n;j++)
   {
    if(i!=j)
        {M[i]+=a[i][j]*x[j];}
   }
   x[i] = (b[i] - M[i])/a[i][i]; //迭代 
  }
  cout<<t++;
  for(int i=0;i<n;i++)
      cout<<"\t"<<fixed<<setprecision(10)<<x[i];
 cout<<endl;
 }

 //return 0;
}



void Jacobi()
 {
     cout<<"Jacobi(雅可比):\n";
  int h=0;//迭代次数
  while(h<40)
  {
   for(int i=0;i<n;i++)
   {
     M[i]=0;
    for(int j=0;j<n;j++)
    {
     if(i!=j)
        M[i]+=(a[i][j]*x[j]);
    }
    N[i] = (b[i]-M[i])/a[i][i];
   }
   for(int k=0;k<n;k++)//将x的值一次性的代换 
     x[k] = N[k];
   cout<<h++;
   for(int i=0;i<n;i++)
    cout <<"\t"<<x[i];
   cout<<endl;
  }
  //return 0;
 }
void Deletex()//重新设置x 
{
     for(int i=0;i<n;i++)
        x[i]=0;
}
int main()
{
    initializtion();
    Gaussseidel();
    Deletex();
    Jacobi();
 
 
 system("pause");
 
 return 0;
}

 
 
 
