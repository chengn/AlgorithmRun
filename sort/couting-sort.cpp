
//11-10-06 09:22


#include <stdlib.h>
#include <stdio.h>
#include <time.h>


#define n 30

int main(int argc, char* argv[])
{
 int a[n]={0},b[n]={0},i,j,c=0;
  
 srand(time(0)); //��ȡ���seed
 for(i=0;i<n;i++) //�����ʼ��
 {
  a[i]=rand()/1000+1;
  for(j=0;j<n;j++) //�ж�����Ԫ�ز�����ͬ
  {
   if(i!=j)
    if(a[i]==a[j])
    {
     i--;
     break;
    }
  }
  
  
 }

 printf("��ʾԭʼ����a\n");
 for(i=0;i<n;i++)
 {
  printf("a[%2d]=%3d  ",i,a[i]);
  if(i%5==4) printf("\n");
 }

 for(i=0;i<n;i++) //��ȡһ����
 {
  for(j=0;j<n;j++) //�ֱ�Ƚ�
  {
   if(a[i]>a[j]) c++; //����ҵ�С����c��һ
  }
  b[c]=a[i]; //��a�����ѱȽϹ���Ԫ�طŵ�b�������ȷλ�ü�cλ��
  c=0; //c���㣬������һ��Ԫ�صıȽ�
 }

 printf("��ʾ���������b\n");
 for(i=0;i<n;i++)
 {
  printf("b[%2d]=%3d  ",i,b[i]);
  if(i%5==4) printf("\n");
 }
while(1);
 return 0;

}


