

/*
  Name: ∂—≈≈–Ústl 
  Copyright: 
  Author: TrueCN
  Date: 04-11-06 00:19
  Description: 
*/

#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

int const len=100;//The max size of heap

int main()
{
    int iv[100],n;
    cin>>n;
    for(int i=0;i<n;i++)
       cin>>iv[i];
    vector<int>ivec(iv,iv+n);
    make_heap(ivec.begin(),ivec.end());
    for(int i =0;i<ivec.size();++i)
       cout<<ivec[i]<<' ';
    cout<<endl;
    
    cout<<ivec.size()<<endl;
    
    sort_heap(ivec.begin(),ivec.end());
    for(int i =0;i<ivec.size();++i)
        cout<<ivec[i]<<' ';
    cout<<endl;
    
    
    system("pause");
    return 0;
}
 
