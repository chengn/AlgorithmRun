
//ð���������� 

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
   if(f==0)break;//stopð������
  }
}

//�����f����Ǿ�����ƶ�����¼��������ֵ�ԭʼλ�� 
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
   if(f==0)break;//stopð������
  }
}
