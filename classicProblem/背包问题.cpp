
/*
  Name: 
  Copyright: 
  Author: 
  Date: 11-06-07 19:28
  Description: 
*/


#include <iostream.h>
#include<iomanip.h>
#include<string.h>
int min(int w,int c)
{
 int temp;
 if (w<c) temp=w;
 else
 temp=c;
 return temp;
}
int max(int w,int c)
{
 int temp;
 if (w>c) temp=w;
 else
 temp=c;
 return temp;
}
void knapsack(int v[],int w[],int c,int n,int**m)      //求最优值
{
  int jmax=min(w[n]-1,c);
  for(int j=0;j<=jmax;j++)
    m[n][j]=0;
  for(int jj=w[n];jj<=c;jj++)
    m[n][jj]=v[n];
  for(int i=n-1;i>1;i--){                           //递归部分
    jmax=min(w[i]-1,c);
    for(int j=0;j<=jmax;j++)
      m[i][j]=m[i+1][j];
    for(int jj=w[i];jj<=c;jj++)
      m[i][jj]=max(m[i+1][jj],m[i+1][jj-w[i]]+v[i]);
      }
  m[1][c]=m[2][c];
  if(c>=w[1])
     m[1][c]=max(m[1][c],m[2][c-w[1]]+v[1]);
 cout<<"最优值："<<m[1][c]<<endl;
/* for(int l=2;l<=n;l++)
  for(int j=0;j<=c;j++)
  {
   cout<<m[l][j]<<setw(c-1);
 }    
  cout<<endl;
  */
  cout<<"*******************************************"<<endl;
}

int traceback(int **m,int w[],int c,int n,int x[])      //回代，求最优解
{
 cout<<"得到的一组最优解如下:"<<endl;
  for(int i=1;i<n;i++)
  if(m[i][c]==m[i+1][c]) x[i]=0;
  else {x[i]=1;
    c-=w[i];}
  x[n]=(m[n][c])?1:0;
  for(int y=1;y<=n;y++)
  {
   cout<<setw(5)<<x[y];
  }
  return x[n];
  
}
int  main()
{
 int n,c;
 int **m;
 cout<<"&&&&&&&&&&&&&&&&&&&&&欢迎使用0-1背包问题程序&&&&&&&&&&&&&&&&&&&"<<endl;
 cout<<"请输入物品个数和重量上限:";
 cin>>n>>c;
   int *v=new int[n+1];
 cout<<"Pls input the property (v[i]):"<<endl;
 for(int i=1;i<=n;i++)
  cin>>v[i];
 int *w=new int[n+1];
 cout<<"Pls input the weight (w[i]):"<<endl;
 for(int j=1;j<=n;j++)
  cin>>w[j];
 int *x=new int[n+1];
 m=new int*[n+1];  //动态的分配二维数组
 for(int p=0;p<n+1;p++)
 {
  m[p]=new int[c+1];
} 
 
 knapsack(v,w,c,n,m);
 traceback(m,w,c,n,x);
 
 
 cout<<endl;
 system("pause");

}

