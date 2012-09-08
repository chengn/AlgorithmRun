

#include<iostream>
using namespace std;



#define N 50

int main(int argc, char* argv[])

{

	int i,j,n,s=0;

	double A[N][N],X[N];

	void line_equations(double A[][50],double X[],int n=1);

//变量的定义

	cout<<"请输入方程的阶数n:";

	cin>>n;

	cout<<"请输入方程组的系数增广矩阵:"<<endl;

	for(i=0;i<=n-1;i++){

		for(j=0;j<=n;j++){

			cout<<"A["<<i<<"]["<<j<<"]=";

			cin>>A[i][j];

		}

	};

    line_equations(A,X,n);

//方程组的系数增广矩阵的输入

	cout<<"下面是方程组的解:"<<endl;

	for(i=0;i<=n-1;i++){

		cout<<"X["<<i<<"]="<<X[i]<<endl;

	};

	cin.get();

	cin.get();

	return 0;

}



void line_equations(double A[][50],double X[],int n=1){

	int i,j,k,s=0;

	double temp;

	if(n==1 && A[0][0]!=0){

		X[0]=A[0][1]/A[0][0];

		return ;

	};

//为一阶时直接求出解

	for(k=0;k<=n-2;k++){

		for(i=k;i<=n;i++){

			if(A[i][k]!=0) break;

		};                         //求出?/textarea><BR>

		if(i>=n){

			cout<<"无解!"; return ;

		}; //若在化归上三角矩阵的时候碰到有缺阶数的时候，此时无解或有无穷多解，统一为无解

		if(i!=k){

			for(j=k;j<=n;j++){

				temp=A[k][j];

				A[k][j]=A[i][j];

				A[i][j]=temp;

			};

		};                        //第一个不为0的行来与k行交换，以免除数为0

		for(i=k+1;i<=n-1;i++){

			for(j=k+1;j<=n;j++){

				A[i][j]-=((A[i][k]/A[k][k])*A[k][j]);

			};

			A[i][k]=0;

		};                 //第k次循环时，将第1列化为0

	};

//至此，将方程组的系数增广矩阵化为了上三角阵

	X[n-1]=A[n-1][n]/A[n-1][n-1];   //从下向上迭代求出X[k],先求最后一个

	for(i=n-2;i>=0;i--){

		for(j=n-2;j>=i;j--){

			A[i][n]-=X[j+1]*A[i][j+1];

		};

		X[i]=A[i][n]/A[i][i];

	};

//迭代求出X[k]

return;

}
