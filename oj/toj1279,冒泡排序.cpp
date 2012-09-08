/*int m,i,M[1001],N[1001],f;
  cin>>m;
  for(i=0;i<m;i++)
   cin>>M[i];
  //√∞≈›≈≈–Ú
  while(1){
   f=0;
  for(i=0;i<m-1;i++)
   if(M[i]>M[i+1])
   {
    swap(M[i],M[i+1]);
    f=1;
   }
   if(f==0)break;//stop√∞≈›≈≈–Ú
  }
  for(i=0;i<m;i++)
   cout<<M[i]<<' ';*/
/*1279
ac   2006.8.10  */

#include<iostream>
using namespace std;
int main()
{
 int n;
 cin>>n;
 while(n-->0)
 {
  int m,i,M[1001],N[1001],f;
  cin>>m;
  for(i=0;i<m;i++)
   cin>>M[i];
  //√∞≈›≈≈–Ú
  while(1){
   f=0;
  for(i=0;i<m-1;i++)
   if(M[i]>M[i+1])
   {
    swap(M[i],M[i+1]);
    f=1;
   }
   if(f==0)break;//stop√∞≈›≈≈–Ú
  }
  int max=0;
     for(i=0;i<m;i++)
  {
   N[i]=M[i]*(m-i);
   if(N[i]>max)
    max=N[i];
  }
  cout<<max<<endl;
 }
}
