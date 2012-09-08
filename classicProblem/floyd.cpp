
/*
  Name: floyd--warshall 最短路经算法
  Copyright: 
  Author: TrueCN
  Date: 01-12-06 22:10
  Description: compile and run in Dev-C++ 4.9.9.2
*/


#include<iostream>
using namespace std;

int f[100][100],n;

int floyed()
{
	int i,j,k;
	for (k=1;k<=n;k++)
		for (i=1;i<=n;i++)
			for (j=1;j<=n;j++)
				if (f[i][j]>f[i][k]+f[k][j])
					f[i][j]=f[i][k]+f[k][j];
   
   return 0;

}

int main()
{
    int i,j;
    cout<<"input vertex:\n";
    cin>>n;
    cout<<"input lenth of path,if no path input 1000000\n";
    for(i=1;i<=n;i++)
    {
       for(j=1;j<=n;j++)
           cin>>f[i][j];
    }
    cout<<"input path you want know:\n";
    int m,h;
    cin>>m>>h;
    floyed();
    cout<<"the lenth of shortest path is:";
    if(f[m][h]!=1000000)
       cout<<f[m][h]<<endl;
    else
       cout<<"no joint!\n";
       
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            if(f[i][j]!=1000000)cout<<i<<" to "<<j<<" is "<<f[i][j]<<endl;
            else  cout<<i<<" to "<<j<<" is no path\n ";
        }
    }
    
    
    system("\n\npause");
    
}
