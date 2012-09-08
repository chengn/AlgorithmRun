
//29-12-06 23:53

#include<iostream>
#include<conio.h>
#include<stdio.h>
using namespace std;

const int n=20;
void creatheap(int *heap,int n)
{
     for(int i=n/2;i>=1;i--)
     {
             int y=heap[i];
             int c=2*i;
             while(c<=n)
             {
                        if(c<n&&heap[c]<heap[c+1])
                            c++;
                        if(y>=heap[c])break;
                        swap(heap[c/2],heap[c]);
                        c*=2;
             }
     }
     for(int i=1;i<=n;i++)
        cout<<heap[i]<<' ';
     cout<<endl;
}

void heap_sort(int *heap,int n)
{
     for(int i=n;i>=1;i--)
     {
             if(n==0)break;
             swap(heap[1],heap[i]);
             creatheap(heap,i-1);
     }
     for(int i=1;i<=n;i++)
        cout<<heap[i]<<' ';
     cout<<endl;
}
int main()
{
    int heap[n],flag;
    cout<<"input 1 or 2\n";
    cin>>flag;
    for(int i=1;i<=n;i++)
    {
       if(flag==1)heap[i]=rand()%n;
       else heap[i]=i;
    }  
    creatheap(heap,n);
    heap_sort(heap,n);
    
    cout<<"press any key...\n";
    getch();
    
    return 0;
}
