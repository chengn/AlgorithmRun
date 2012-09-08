 
 //25-11-06 19:54

 

/*
所谓的龙贝格求积法就是联合使用逐次复合梯形公式步长逐次分半法和理查逊外推法。步骤如下：
1、首先将求积区间[a,b]逐步等分，步长依次为
h= 2(b-a),j=0，1，2，…，k
用复合梯形公式计算得
T， T，…，T
在已经求出T，T的情形，根据理查逊外推法，按公式　
T＝T＋
求T。　若｜T－T｜＜精度要求，则外推过程结束。

*/
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>

float x[100];
float f[100];
float a,b;
int n;
void trapezia(float y,float *S)
{    
    int i,t;
    t=(b-a)/y;
 for(i=0;i<=t;i++)
  x[i]=a+y*i;
 for(i=0;i<=t;i++)
 {
  f[i]=sin(x[i])/x[i];
  if(x[i]==0)
   f[i]=1;
 }
    (*S)=y*(f[0]+f[t])/2;
 for(i=1;i<t;i++)
   (*S)+=(f[i]*y);
}
void longbig(int l,float *U)
{
     float h; 
  float *S;
     float T[20],R[20];
     S=R;
     int i,j;
     h=b-a;
     for(i=0;i<=l;i++)
  {
   trapezia(h/pow(2,i),S);
         T[i]=*S;
  }
      for(j=l;j>0;j--)
         for(i=0;i<j;i++)
             T[i]=T[i+1]+((T[i+1]-T[i])/(pow(4,(l-j+1))-1));
     (*U)=T[0];
}

int main()
{
    float p,q;
 float H[1];
 int m;
 printf("请输入积分上限\n");
 scanf("%f",&b);
 printf("请输入积分下限\n");
    scanf("%f",&a);
 printf("采用多少节点定步长复化梯形公式?\n");
 scanf("%d",&n);
    q=(log(n-1))/(log(2));
 m=int(q+0.5);
    longbig(m,H);
    p=H[0];
 printf("积分结果为\n");
    printf("%f\n",p);
}
 
 

