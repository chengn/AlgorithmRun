#include <stdio.h>



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


int read()
{
	int i,j,t,y,person,time,max,temp;
	while (1)
	{
		scanf("%d",&n);
		if (!n) return 0;
		if (n==1) {printf("1 0\n");continue;}
		for (i=0;i<100;i++)
			for (j=0;j<100;j++)
				f[i][j]=10000000;
		for (i=1;i<=n;i++)
		{
			scanf("%d",&t);
			for (j=1;j<=t;j++)
			{
				scanf("%d %d",&y,&temp);
				f[i][y]=temp;
			}
		}
		floyed();
		time=10000000; 
		for (i=1;i<=n;i++)
		{
			max=0;
			for (j=1;j<=n;j++)
				if (i!=j) max=max<f[i][j]?f[i][j]:max;
			if (time>max)
			{
				time=max;
				person=i;
			}
		}
		if (time!=10000000) printf("%d %d\n",person,time);
		else printf("disjoint\n");
	}
}


int main()
{
	read();
	return 0;
}

