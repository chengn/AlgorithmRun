/*
  Name: Merge Sort
  Copyright: 
  Author:  chengn(Martin Stallman) 
  Date: 08/09/12 21:41
  Description: 
*/


#include <stdio.h>
#include <stdlib.h> 
#include <iostream> 

// 
bool const IS_PRINT_DETAIL = true; 
int const ARRAY_SIZE=10;
int const RAND_MAX_VALUE = 100;

//method declare region =========================================== 
void mergeSortTest(); 
void merge(int *array,int low,int mid,int high); 
void mergeSort(int *array,int low,int high); 
void genericNum(int *array,int count); 
void printItem(int * array); 
//================================================================= 

/*
  program entrance,main method 
*/ 
int main(int argc, char *argv[])
{
    printf("[info]into main \n"); 
    mergeSortTest();
  //  int m = 0; 
//    test(&m) ; 
    
    system("PAUSE");
    while(1){} 
    
    printf("[info]quit main \n"); 
    return 0; 
} 



void mergeSortTest()
{
    printf("[info]into mergeSortTest \n"); 
    int array[ARRAY_SIZE];
    genericNum(array,ARRAY_SIZE);
    printf("original numbers are follow: "); 
    printItem(array); 
    
    mergeSort(array,0,ARRAY_SIZE-1); 
    printItem(array); 
    printf("[info]quit mergeSortTest \n"); 
} 

/*
  @Description:mergeSort
  @Param: 
      array:sorted number sequence
      low:  low position
      high: high position    
*/
void mergeSort(int array[],int low,int high)
{
    printf("[info]into mergeSort,%d,%d \n",low,high); 
    if(low < high) 
    {
        int mid = (high - low) / 2;
        //sort left 
        if(low < mid)
        { 
            mergeSort(array,low,mid);
        } 
        //sort right 
        if(mid+1<high)
        { 
            mergeSort(array,mid+1,high);
        } 
        //merge left & right 
        merge(array,low,mid,high);          
    } 
    printf("[info]quit mergeSort \n"); 
} 


/*
  @Description:merge sub sequence
  @Param: 
      array:sorted number sequence
      low:  low position
      mid:  middle position
      high: high position   
*/ 
void merge(int array[],int low,int mid,int high)
{
    printf("[info]into merge \n"); 
    //mid belong left.so left plus 1; 
    int leftCount =  mid-low+1;
    int rightCount =  high-mid; 
    int leftArray[leftCount];//begin 0,so +1 
    int rightArray[rightCount]; 
    
    for(int i=0;i<leftCount;++i) 
    {
        leftArray[i] = array[low+i]; 
    } 
    
    for(int i=0;i<leftCount;++i) 
    {
        rightArray[i] = array[mid+1+i]; 
    } 
    int leftPos = 0;
    int rightPos = 0; 
    int arrayPos = low; 
    while(leftPos < leftCount && rightPos < rightCount)
    {
        int bufValue;
        if(leftArray[leftPos] <= rightArray[rightPos])
        {
            bufValue = leftArray[leftPos];
            ++leftPos; 
        } 
        else
        {
            bufValue = rightArray[rightPos];
            ++rightPos; 
        } 
        array[arrayPos++]  = bufValue; 
    } 
    while(leftPos < leftCount) 
    {
        array[arrayPos++] = leftArray[leftPos++]; 
    } 
    while(rightPos < rightCount)
    {
        array[arrayPos++] = rightArray[rightPos++]; 
    } 
    printf("[info]quit merge \n"); 
} 

/*
  @Description:generic number sequence
  @Param: 
      array:sorted number sequence
      count: sequence number count 
*/ 
void genericNum(int *array,int count)
{
    printf("[info]into genericNum \n"); 
     srand((unsigned)time(NULL));
     for(int i=0;i<count;i++)
     {
         array[i] = rand()%RAND_MAX_VALUE;
     }
    printf("[info]quit genericNum \n"); 
}

/*
  @Description:print number sequence to console
  @Param: 
      array:sorted number sequence
*/ 
void printItem(int * array)
{
     for(int i=0;i<ARRAY_SIZE;i++)
     {
         printf("%d ",array[i]) ; 
     }
     printf("\n");
}



