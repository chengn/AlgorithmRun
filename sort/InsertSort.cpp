/*
  Name:     insert sort
  Copyright: 
  Author:    chengn
  Date: 08/09/12 18:45
  Description: 
*/

#include <cstdlib> 
#include <iostream> 

using namespace std;

bool const IS_PRINT_DETAIL = true; 
int const ARRAY_SIZE=6;
int const RAND_MAX_VALUE = 100;


int insertSortTest();
int insertSort(int *array,int sortType); 
void genericNum(int *array,int count); 
void printItem(int * array); 

// 
int main()
{
    insertSortTest();
    
    system("PAUSE");
    return EXIT_SUCCESS; 
} 

// 
int insertSortTest()
{
    int array[ARRAY_SIZE];
    genericNum(array,ARRAY_SIZE);
    printf("original numbers are follow: "); 
    printItem(array); 
    
    //printf("order by asc:\n"); 
    insertSort(array,0);
    printItem(array); 
    
    //printf("order by desc:\n"); 
   // insertSort(array,1);
   // printItem(array); 
     
} 



/**
 sortType£º0--asc;
           1--desc; 
*/ 
int insertSort(int *array,int sortType)
{
    int sortedNum; 
    for(int i=1;i<ARRAY_SIZE;++i)
    {      
        sortedNum = array[i]; 
        if(IS_PRINT_DETAIL)
        {
            //can print all number to know sort detail step;
            printItem(array);
            printf("step %4d,sorted [%4d]    ",i,sortedNum); 
        }
        for(int k=i-1;k>=0;--k)
        {
            if(0 == sortType)
            {
                 if(array[k] > sortedNum)
                 {
                     array[k+1] = array[k];//bcz k is begin i-1,so array[k+1] is not over 
                     array[k] = sortedNum;
                 }
                 else
                 {
                     break; 
                 } 
                 
            } 
            else if(1 == sortType) 
            {
                
                 if(array[k] < sortedNum)
                 {
                     array[k+1] = array[k];//bcz k is begin i-1,so array[k+1] is not over              
                     array[k] = sortedNum;
                 } 
                 else
                 {
                     break; 
                 }  
  
          } 
        }  
         
    } 
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

/*
*/ 
void printItem(int * array)
{
     for(int i=0;i<ARRAY_SIZE;i++)
     {
         cout<<array[i] << " " ;
     }
     cout<<endl;
}


