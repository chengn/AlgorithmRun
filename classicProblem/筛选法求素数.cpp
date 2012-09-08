/*
 *******************
  *  筛选法求素数   *
  *******************
    */
//(1)

#include<iostream>
using namespace std;
const int size=100000;//the size of prime
int main()
{
 int i,k,n=0,M[size];
 for(i=0;i<size;i++)
  M[i]=i;
 for(i=2;i*i<size;i++){  //筛选法求素数
  for(k=i*i;k<size;k+=i)
   M[k]=0;
 }
 for(k=2;k<size;k++)
  if(M[k]!=0){
   cout<<M[k]<<" ";
   n++;
  }
 cout<<endl<<n<<endl;//素数的个数
 while(1);
}

////////////////////////////////////////

//(2)构件类
/*
#include <iostream>
#include <bitset>
using namespace std;

#define FALSE 0

#define bSize 1000

typedef  bitset<bSize> Prime_Set;

Prime_Set primes;

void make_primes()
{
 primes.set();
 for( int i = 2; i*i < bSize; i++ )
  if( primes.test(i) )
   for(int k = i*i; k < bSize; k += i)
    primes.set( k, FALSE );
}

main()
{
 make_primes();

 for(int k = 2; k<bSize; k++)
  if( primes.test(k) )
   cout << k << endl;

 return 0;
}
*/
 

