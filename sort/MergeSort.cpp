/*
  Name: Merge Sort
  Copyright: 
  Author:  chengn(Martin Stallman) 
  Date: 08/09/12 21:41
  Description: 
*/


#include <stdio.h>
#include <stdlib.h> 
#include <time.h> 


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
    //test merge sort 
    mergeSortTest();
    system("PAUSE");
    printf("[info]quit main \n"); 
    return 0; 
} 

/*
  test merge sort 
*/ 
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
    return; 
} 

/*
  @Description:mergeSort
  @Param: 
      array:sorted number sequence
      low:  low position
      high: high position    
*/
void mergeSort(int *array,int low,int high)
{
    //printf("[info]into mergeSort,%d,%d \n",low,high); 
    int mid = (high + low) / 2;
    if(low < high) 
    {
        //sort left 
        mergeSort(array,low,mid);
        //sort right 
        mergeSort(array,mid+1,high);
        //merge left & right 
        merge(array,low,mid,high);          
    } 
    //printf("[info]quit mergeSort \n"); 
    return; 
} 


/*
  @Description:merge sub sequence
  @Param: 
      array:sorted number sequence
      low:  low position
      mid:  middle position
      high: high position   
*/ 
void merge(int *array,int low,int mid,int high)
{
    //printf("[info]into merge (%d,%d,%d)\n",low,mid,high); 
    int tempArray[high-low+1]; //temp array,sava sorted number; 
    int pos = 0; //temp arra pos 
    int leftPos = low; //left pos 
    int rightPos = mid+1; // right pos 
    
    //go left and right 
    while(leftPos <= mid && rightPos <= high) //this must = 
    {
        int bufValue;
        //left pos go 
        if(array[leftPos] < array[rightPos])//this cann;t hava = 
        {
            tempArray[pos++] = array[leftPos++]; 
        } 
        else//right pos go 
        {
            tempArray[pos++] = array[rightPos++]; 
        } 
    } 
    //go alone left 
    while(leftPos <= mid) //this must hava = 
    {
        tempArray[pos++] = array[leftPos++]; 
    } 
    //go alone right 
    while(rightPos <= high)//this must hav =  
    {
        tempArray[pos++] = array[rightPos++]; 
    } 
    //copy to original array
    for(int i=0;i<pos;i++)
    {
        array[low+i] = tempArray[i]; 
    } 
    //printf("[info]quit merge \n"); 
    return; 
} 

/*
  @Description:generic number sequence
  @Param: 
      array:sorted number sequence
      count: sequence number count 
*/ 
void genericNum(int *array,int count)
{
    //printf("[info]into genericNum \n"); 
     srand((unsigned)time(NULL));
     for(int i=0;i<count;i++)
     {
         array[i] = rand()%RAND_MAX_VALUE;
     }
    //printf("[info]quit genericNum \n"); 
    return; 
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
     return; 
}



