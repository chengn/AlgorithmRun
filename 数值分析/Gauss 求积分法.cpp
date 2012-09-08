

#include<iostream>
using namespace std;



#define N 50

int main(int argc, char* argv[])

{

	int i,j,n,s=0;

	double A[N][N],X[N];

	void line_equations(double A[][50],double X[],int n=1);

//�����Ķ���

	cout<<"�����뷽�̵Ľ���n:";

	cin>>n;

	cout<<"�����뷽�����ϵ���������:"<<endl;

	for(i=0;i<=n-1;i++){

		for(j=0;j<=n;j++){

			cout<<"A["<<i<<"]["<<j<<"]=";

			cin>>A[i][j];

		}

	};

    line_equations(A,X,n);

//�������ϵ��������������

	cout<<"�����Ƿ�����Ľ�:"<<endl;

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

//Ϊһ��ʱֱ�������

	for(k=0;k<=n-2;k++){

		for(i=k;i<=n;i++){

			if(A[i][k]!=0) break;

		};                         //���?/textarea><BR>

		if(i>=n){

			cout<<"�޽�!"; return ;

		}; //���ڻ��������Ǿ����ʱ��������ȱ������ʱ�򣬴�ʱ�޽���������⣬ͳһΪ�޽�

		if(i!=k){

			for(j=k;j<=n;j++){

				temp=A[k][j];

				A[k][j]=A[i][j];

				A[i][j]=temp;

			};

		};                        //��һ����Ϊ0��������k�н������������Ϊ0

		for(i=k+1;i<=n-1;i++){

			for(j=k+1;j<=n;j++){

				A[i][j]-=((A[i][k]/A[k][k])*A[k][j]);

			};

			A[i][k]=0;

		};                 //��k��ѭ��ʱ������1�л�Ϊ0

	};

//���ˣ����������ϵ���������Ϊ����������

	X[n-1]=A[n-1][n]/A[n-1][n-1];   //�������ϵ������X[k],�������һ��

	for(i=n-2;i>=0;i--){

		for(j=n-2;j>=i;j--){

			A[i][n]-=X[j+1]*A[i][j+1];

		};

		X[i]=A[i][n]/A[i][i];

	};

//�������X[k]

return;

}
