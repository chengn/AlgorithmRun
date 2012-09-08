
//sort
//cheng
//2006.9.29
#include<vector>
#include<iostream>
#include<iterator>
using namespace std;

int main()
{
    cout<<"  tips:\n      this can sort 10000 numbers"<<endl<<endl<<endl;
    cout<<"  will you  want to sort?(1/0)"<<endl;
    cout<<"       1(yes)    0(no)" <<endl<<"       :";
    int result;
    cin>>result;
    while(result)
    {
    int m,M[10000];
    cout<<"How many number you want to sort:"<<endl;
    cin>>m;
  
    cout<<"input number you want to sort(depart by space):"<<endl;  
    for(int i=0;i<m;i++)
       cin>>M[i];
       
    vector<int> iv(M,M+m);
  
    cout<<"Result you want is:"<<endl;
    sort(iv.begin(),iv.end());
    copy(iv.begin(),iv.end(),ostream_iterator<int>(cout," "));
    cout<<endl<<endl;
    
    cout<<"can you continue?(0(n)/1(y))"<<endl;
    cin>>result;
}
    
    
}
