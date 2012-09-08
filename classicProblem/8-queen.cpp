


#include <stdio.h> 
#include <conio.h> 
//#include <math.h> 
#include <stdlib.h> 


#define QUEENS 8 

//!记录解的序号的全局变量? 
int iCount = 0; 

//!记录皇后在各列上的放置位置的全局数组? 
int Site[QUEENS]; 

//!递归求解的函数? 
int Queen(int n); 

//!输出一个解? 
int Output(); 

//!判断第n个皇后放上去之后,是否有冲突? 
int IsValid(int n); 

/*----------------------------Main:主函数?----------------------------*/ 
int main() 
{ 
    Queen(0); 
    getch(); 
     return 0;
} 

/*-----------------Queen:递归放置第n个皇后,程序的核心!----------------*/ 
int Queen(int n) 
{ 
    int i;
  if(n == QUEENS) 
  { 
    Output(); 
    return 0; 
   }        
   //!n还没到8,在第n列的各个行上依次试探? 
   for(i = 1 ; i <= QUEENS ; i++) 
   { 
         //!在该列的第i行上放置皇后? 
         Site[n] = i; 

         //!如果放置没有冲突,就开始下一列的试探? 
         if(IsValid(n)) 
               Queen(n + 1); 
   } 
} 

/*------IsValid:判断第n个皇后放上去之后,是否合法,即是否无冲突?------*/ 
int IsValid(int n) 
{ 
     int i; 

     //!将第n个皇后的位置依次于前面n-1个皇后的位置比较? 
     for(i = 0 ; i < n ; i++) 
     { 
           //!两个皇后在同一行上,返回0? 
           if(Site[i] == Site[n]) 
                 return 0; 

           //!两个皇后在同一对角线上,返回0? 
           if(abs(Site[i] - Site[n]) == (n - i)) 
                 return 0;
     } 

     //!没有冲突,返回1? 
     return 1; 
} 

/*------------Output:输出一个解,即一种没有冲突的放置方案?------------*/ 
int Output() 
{ 
     int i; 

     //!输出序号? 
     printf("No.%-5d" , ++iCount); 

     //!依次输出各个列上的皇后的位置,即所在的行数? 
     for(i = 0 ; i < QUEENS ; i++) 
           printf("%d " , Site[i]); 

     printf("\n"); 
}
