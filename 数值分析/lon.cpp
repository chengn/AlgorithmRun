 
 //25-11-06 19:54

 

/*
��ν���������������������ʹ����θ������ι�ʽ������ηְ뷨�����ѷ���Ʒ����������£�
1�����Ƚ��������[a,b]�𲽵ȷ֣���������Ϊ
h= 2(b-a),j=0��1��2������k
�ø������ι�ʽ�����
T�� T������T
���Ѿ����T��T�����Σ��������ѷ���Ʒ�������ʽ��
T��T��
��T��������T��T��������Ҫ�������ƹ��̽�����

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
 printf("�������������\n");
 scanf("%f",&b);
 printf("�������������\n");
    scanf("%f",&a);
 printf("���ö��ٽڵ㶨�����������ι�ʽ?\n");
 scanf("%d",&n);
    q=(log(n-1))/(log(2));
 m=int(q+0.5);
    longbig(m,H);
    p=H[0];
 printf("���ֽ��Ϊ\n");
    printf("%f\n",p);
}
 
 

