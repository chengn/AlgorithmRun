//2010  ÇóËØÊı,dp
#include<stdio.h>
int main()
{
 int n,i,M[10000];
 while(scanf("%d",&n)&&n!=0)
 {
  int f,j,b=0;
  M[0]=2;
  if(n>=3){
  for(i=3;i<=n;i++)
  {
   f=0;
   for(j=2;j<i;j++){
    if(i%j==0){
     f=1;break;}
   }
   if(f==0){
    b++;
    M[b]=i;
   }
  }
  for(i=0;i<=b;i++)
   printf("%d ",M[i]);
  printf("\n");
  }
  int sum=0,g=0,h=0;
  for(i=0;i<=b;i++)
  {
   sum+=M[i];
   printf("%d ",sum);
   if(sum>=n){
    if(sum==n)g++;
    sum=0;
    h++;
    i=h-1;
    printf("\n");
   }
  }
  printf("\n%d\n",g);
 }
 return 0;
}
