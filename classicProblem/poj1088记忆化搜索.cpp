#include<stdio.h>
#include<stdlib.h>
#define MAX 100

int region[MAX][MAX];
int dp[MAX][MAX];
int r;
int c;
int Max(int a,int b){
    if(a>b)return a;
    else return b;
}
int Deep(int i,int j){
    if(dp[i][j]>0)return dp[i][j];
    else {
        dp[i][j]=0;
        if((i-1)>=0&&region[i][j]>region[i-1][j]){
            if(dp[i-1][j]>0)dp[i][j]=Max(dp[i][j],dp[i-1][j]+1);
            else dp[i][j]=Max(dp[i][j],Deep(i-1,j)+1);
        }
        if(i+1<r&&region[i][j]>region[i+1][j]){
            if(dp[i+1][j]>0)dp[i][j]=Max(dp[i][j],dp[i+1][j]+1);
            else dp[i][j]=Max(dp[i][j],Deep(i+1,j)+1);
        }
        if(j-1>=0&&region[i][j]>region[i][j-1]){
            if(dp[i][j-1]>0)dp[i][j]=Max(dp[i][j],dp[i][j-1]+1);
            else dp[i][j]=Max(dp[i][j],Deep(i,j-1)+1);
        }
        if(j+1<c&&region[i][j]>region[i][j+1]){
            if(dp[i][j+1]>0)dp[i][j]=Max(dp[i][j],dp[i][j+1]+1);
            else dp[i][j]=Max(dp[i][j],Deep(i,j+1)+1);
        }
    }
    return dp[i][j];
}          
                   
    
int main(){
    int i;
    int j;
    int max=-1;
    
    scanf("%d %d",&r,&c);
    for(i=0;i<r;i++)
        for(j=0;j<c;j++){
            scanf("%d",&region[i][j]);
            dp[i][j]=-1;
        }    
    for(i=0;i<r;i++)
        for(j=0;j<c;j++){
            dp[i][j]=Deep(i,j);
            if(dp[i][j]>max)max=dp[i][j];
        }
    printf("%d\n",max+1);        
    system("PAUSE");
    
  
    return 0;
}
