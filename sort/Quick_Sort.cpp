//Quick Sort
/*
  Name: 
  Copyright: 
  Author: 
  Date: 23-07-11 00:53
  Description: 
*/

#include<cmath>
#include<ctime> 
#include<iostream>
#include<algorithm>

using namespace std;

int const arrayCnt=15;
int const randMax = 100;


/*
*/ 
void printItem(int * array)
{
     for(int i=0;i<arrayCnt;i++)
     {
         cout<<array[i] << " " ;
     }
     cout<<endl;
}

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
         array[i] = rand()%randMax;
     }
}

/*
*/ 
void exchange(int *a,int *b)
{
     int temp = *a;
     *a = *b;
     *b = temp;
}

/*
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
void quickSort(int* array,int begin,int end)
{
     int pivot;
     if(begin < end)
     {
         pivot = getPivot(array,begin,end);
         quickSort(array,begin,pivot-1);
         quickSort(array,pivot+1,end);
     }
}



/////////////////////////////////////////////////////////////////////////////// 
int quickSortTest()
{
    int array[arrayCnt];
    for(int i=0;i<arrayCnt;i++)
    {
        genericNum(array,arrayCnt);
        printItem(array);
        quickSort(array,0,arrayCnt-1);
        cout<<endl;
        printItem(array);
    //    sort(array);
    //    Print(array);
        cout<<"========================================================="<<endl;
    }
}

int main()
{
    quickSortTest(); 
    
    system("pause");
} 
