
//冒泡排序增序 

void bsort(int M[],int m)
{
    int f;
    while(1){
   f=0;
    for(int i=0;i<m-1;i++){
   if(M[i]>M[i+1])
   {
    swap(M[i],M[i+1]);
    f=1;
   }
}
   if(f==0)break;//stop冒泡排序
  }
}

//带标记f，标记具体的移动，记录排序后数字的原始位置 
void bsort(int M[],int m,int F[])
{
    int f;
    while(1){
   f=0;
    for(int i=0;i<m-1;i++){
   if(M[i]>M[i+1])
   {
    swap(M[i],M[i+1]);
    swap(F[i],F[i+1]);
    f=1;
   }
}
   if(f==0)break;//stop冒泡排序
  }
}
