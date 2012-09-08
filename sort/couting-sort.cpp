
//11-10-06 09:22


#include <stdlib.h>
#include <stdio.h>
#include <time.h>


#define n 30

int main(int argc, char* argv[])
{
 int a[n]={0},b[n]={0},i,j,c=0;
  
 srand(time(0)); //获取随机seed
 for(i=0;i<n;i++) //数组初始化
 {
  a[i]=rand()/1000+1;
  for(j=0;j<n;j++) //判断数组元素不能相同
  {
   if(i!=j)
    if(a[i]==a[j])
    {
     i--;
     break;
    }
  }
  
  
 }

 printf("显示原始数组a\n");
 for(i=0;i<n;i++)
 {
  printf("a[%2d]=%3d  ",i,a[i]);
  if(i%5==4) printf("\n");
 }

 for(i=0;i<n;i++) //提取一个数
 {
  for(j=0;j<n;j++) //分别比较
  {
   if(a[i]>a[j]) c++; //如果找到小的则c加一
  }
  b[c]=a[i]; //将a数组已比较过的元素放到b数组的正确位置即c位置
  c=0; //c归零，重新下一个元素的比较
 }

 printf("显示排序后数组b\n");
 for(i=0;i<n;i++)
 {
  printf("b[%2d]=%3d  ",i,b[i]);
  if(i%5==4) printf("\n");
 }
while(1);
 return 0;

}


