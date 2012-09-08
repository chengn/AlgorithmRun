/*   1701  动态规划   局部求和
     
	     **********************************
		 *  2006-08-16 15:18:14 Accepted  *
         *  1701 C 0.6K 0:00.23  604K     *
         **********************************
*/
#include<stdio.h>
int main()
{
 int n,M[1000],j=1;
 scanf("%d",&n);
 while(n-->0)
 {
  int sum,num;
  scanf("%d %d",&sum,&num);
  int i;
  for(i=0;i<num;i++)
  {
   scanf("%d",&M[i]);
  }
  int f,g,h=0,m=0;
  g=num-1;
  while(1)
  {
   f=0;
   for(i=0;i<g;i++)
   {
    int temp;
    if(M[i]>M[i+1]){
     temp=M[i];
     M[i]=M[i+1];
     M[i+1]=temp;
     f=1;
    }
   }
   h+=M[g];
   if(h>=sum)
   {
    m=1;
    break;
   }
   if(f==0)
    break;
   g--;
  }
  printf("Scenario #%d:\n",j);
  if(m==1){
  printf("%d\n\n",num-i);
  }
  else
   printf("impossible\n\n");
  j++;
 }
 return 0;
}

