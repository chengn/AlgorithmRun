
/*
  Name: K-MaxValue.cpp 
  Copyright: 
  Author: chengn(Martin Stallman) 
  Date: 19-09-12 09:30
  Description: 取得第k小的值 
*/


#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std; 

int const ARRAY_SIZE = 15;
int const K_MAX = 5;
int const RAND_MAX_VALUE = 1000; 

//////////Method declare region/////////////////////////////////////////
void printItem(int * array,int begin,int end);
void genericNum(int *array,int count);
int f(int *array,int begin,int end,int k); 
int getPivot(int * array,int begin,int end); 
void exchange(int *a,int *b); 
int getKMaxValue(int *array,int k); 
///////////////endregion/////////////////////////////////////////////// 


/*
  主方法，程度运行入口 
*/ 
int main()
{
    int array[ARRAY_SIZE]; 
    
    genericNum(array,ARRAY_SIZE);
    printItem(array,0,ARRAY_SIZE-1);  
    
    int kValue = getKMaxValue(array,K_MAX);
    printf("%d",kValue); 
    system("pause");
    return 0; 
}  
/*
    得到第k小的值 
*/ 
int getKMaxValue(int *array,int k)
{
    int i=f(array,0,ARRAY_SIZE-1,K_MAX) ;
    return array[i]; 
} 
/*
    得到在数组的begin和end之间第k小值的位置 
*/ 
int f(int *array,int begin,int end,int k)
{
         //pivot is i;left less than and right more than i; 
         int i = getPivot(array,begin,end); 
         int k = K_MAX-1;//第k小数的位置 
         if(k == i)
         {
             return i;
         } 
         else if(k > i)
         {
             return f(array,i,end,k-i); 
         } 
         else
         {
             return f(array,begin,i,k); 
         } 
} 

/*
  利用快排的划分,得到划分点pivot，在pivot的右边是大于pivot，左边是小于pivot的数
  即pivot位置是array中第pivot+1小的数 
  get pivot and make array,
  left number less than pivot number 
  right number more than pivot number
*/ 
int getPivot(int * array,int begin,int end)
{
    int pivot = begin-1;
    int data = array[end];
    for(int j = begin;j<=end-1;j++)
    {
        if(array[j] < data)
        {
            pivot=pivot+1;
            exchange(&array[pivot],&array[j]) ;
        }
    }
    exchange(&array[pivot+1],&array[end]) ;
    return pivot+1;
}

/*
*/ 
void exchange(int *a,int *b)
{
     int temp = *a;
     *a = *b;
     *b = temp;
}

/////////////////Tools Method region///////////////////////////////// 
/*
*/ 
void printItem(int * array,int begin,int end)
{
     for(int i=begin;i<=end;i++)
     {
         cout<<array[i] << " " ;
     }
     cout<<endl;
}

/*
*/ 
void genericNum(int *array,int count)
{
     srand((unsigned)time(NULL));
     for(int i=0;i<count;i++)
     {
         array[i] = rand()%RAND_MAX_VALUE;
     }
}
////////////////////endregion//////////////////////////////////////// 
