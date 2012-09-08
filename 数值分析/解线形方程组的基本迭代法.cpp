

/*
  Name: �����η�����Ļ��������� 
  Copyright: 
  Author: TrueCN
  Date: 15-12-06 17:45
  Description: 
*/
 
#include<iostream>
#include<iomanip>
using namespace std;

int n; //���Է��̵�ά��
double *M;//��������
double *N;//��������
int **a;//���η��̵�ϵ������
int *b;//���������
double *x;//�����

void initializtion()   //��ʼ�����η���
{
 cout<<"�������Է��̵�ά��:  ";
    cin>>n;
 M=new double[n];
 N = new double[n];
 a = new int*[n];
 for(int i=0;i<n;i++)
        a[i] = new int[n];
 b = new int[n];
 x = new double[n]; 
 cout<<"�������η��̵�ϵ������:\n";
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
             cin >> a[i][j];
 cout<<"�������η�����ĳ��������:\n";
 for(int k=0;k<n;k++)
 {
  cin>>b[k];
  x[k] = 0.0;//��ʼ��x 
 }

}



void Gaussseidel()//��˹--���ö������� 
{
     cout<<"Gauss-seidel:\n";
 int t=0;//��������
 while(t<20)//��������,����Ҫ��,�˴����޸�,�ǵ������� 
 {
  for(int i=0;i<n;i++)
  {
   M[i] = 0;       
   for(int j=0;j<n;j++)
   {
    if(i!=j)
        {M[i]+=a[i][j]*x[j];}
   }
   x[i] = (b[i] - M[i])/a[i][i]; //���� 
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
     cout<<"Jacobi(�ſɱ�):\n";
  int h=0;//��������
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
   for(int k=0;k<n;k++)//��x��ֵһ���ԵĴ��� 
     x[k] = N[k];
   cout<<h++;
   for(int i=0;i<n;i++)
    cout <<"\t"<<x[i];
   cout<<endl;
  }
  //return 0;
 }
void Deletex()//��������x 
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

 
 
 
