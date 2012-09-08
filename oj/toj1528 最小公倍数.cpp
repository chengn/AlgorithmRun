
//32 2006-12-17 14:08:25 C 0.7K 0:00.00 600K 
//一组数的最小公倍数的求法 

#include<stdio.h>
int main()
{
    int n;
    long long flag;
    scanf("%d",&n);
    while(n>0)
    {
        int m,num1,i;
        scanf("%d",&m);
        flag=1;
        for(i=0;i<m;i++)
        {
            scanf("%d",&num1);
            int a,b,s;
            if(flag>num1)
               {b=num1;
               s=flag;}
            else {b=flag;
                 s=num1;}
            while(1)
            {
                a=s%b;
                if(a==0)break;
                s=b;
                b=a;
            }
            flag=(flag*num1)/b;
        }
        printf("%d\n",flag);
        n--;
    }
    return 0;
}
