/*    *******************
      *   rand() and    *
      *   bubble sort   *
      *******************


use rand() genarete some number between
0--100.and give correct order use bubble sort(ц╟ещеепР)
   06.8.19     */

#include<iostream>
#include<conio.h>
using namespace std;

const int n=100;
const int k=100;
int main()
{
    cout<<"this is about 0~"<<n-1<<" digits \n\n";
 int i,M[k];
 for(i=0;i<n;i++)
 {
  M[i]=rand()%100;
 }
 cout<<"the rand are:\n";
 for(i=0;i<n;i++)
  cout<<M[i]<<" ";
 cout<<"\n"<<endl;
 
 cout<<"follow is sort:"<<endl<<endl;
 int f;
 while(1)
 {
 f=0;
 for(i=0;i<n-1;i++)
 {
  if(M[i]>M[i+1]){
   swap(M[i],M[i+1]);
   f=1;
  }
 }
 if(f==0)
  break;
 }
 for(i=0;i<n;i++)
  cout<<M[i]<<" ";
  
  cout<<"\n\npress any key to continue!\n";
  getch();
 return 0;
}

